import { app, shell, BrowserWindow, ipcMain } from 'electron'
import { join } from 'path'
import { electronApp, optimizer, is } from '@electron-toolkit/utils'
import icon from '../../resources/icon.png?asset'

import { openNewCmdWithFile } from './utils/child.js'
import { getAppsInfo } from './utils/apps.js'

function createWindow() {
  // 创建一个浏览器窗口
  const mainWindow = new BrowserWindow({
    width: 900,
    height: 670,
    show: false,
    autoHideMenuBar: true,
    ...(process.platform === 'linux' ? { icon } : {}),
    webPreferences: {
      preload: join(__dirname, '../preload/index.js'),
      sandbox: false
    }
  })

  mainWindow.on('ready-to-show', () => {
    mainWindow.show()
  })

  mainWindow.webContents.setWindowOpenHandler((details) => {
    shell.openExternal(details.url)
    return { action: 'deny' }
  })

  // 基于 electron-vite cli 实现的渲染进程的热模块替换（HMR）
  // 开发时加载远程 URL，生产时加载本地 html 文件
  if (is.dev && process.env['ELECTRON_RENDERER_URL']) {
    mainWindow.loadURL(process.env['ELECTRON_RENDERER_URL'])
  } else {
    mainWindow.loadFile(join(__dirname, '../renderer/index.html'))
  }
}

// 当 Electron 完成初始化并准备创建浏览器窗口时，将调用此方法。
// 有些 API 只有在此事件发生后才能使用。
app.whenReady().then(() => {
  // 为 Windows 设置应用用户模型 ID
  electronApp.setAppUserModelId('com.electron')

  // 默认在开发环境通过 F12 打开或关闭 DevTools，
  // 并在生产环境忽略 CommandOrControl + R。
  // 参见 https://github.com/alex8088/electron-toolkit/tree/master/packages/utils
  app.on('browser-window-created', (_, window) => {
    optimizer.watchWindowShortcuts(window)
  })

  // IPC 测试
  // ipcMain.on('ping', () => console.log('pong'))
  ipcMain.on('openApp', async (event, data) => {
    openNewCmdWithFile(data)
  })

  ipcMain.handle('initApps', () => {
    return getAppsInfo()
  })

  createWindow()

  app.on('activate', function () {
    // 在 macOS 上，当点击 dock 图标且没有其他窗口打开时，
    // 常见的做法是重新创建一个窗口。
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})

// 除 macOS 外，当所有窗口都被关闭时退出应用。
// 在 macOS 上，应用程序及其菜单栏通常保持活跃状态，
// 直到用户使用 Cmd + Q 明确退出为止。
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

// 在这个文件中你可以包含你的应用的其他特定主进程代码。
// 你也可以将它们放在单独的文件中，并在这里引入。
