import { is } from '@electron-toolkit/utils'
const { spawn } = require('child_process')
const path = require('path')

function openNewCmdWithFile(command) {
  let fullPath
  // 开发环境和生产环境两套路径
  if (is.dev) {
    fullPath = path.resolve('./resources/bin', command)
  } else {
    fullPath = path.resolve('./resources/app.asar.unpacked', './resources/bin', command)
  }

  // 在 Windows 上，使用 'cmd.exe' 与 '/c' 选项来运行命令
  // 'start' 命令用于打开新的cmd窗口
  // '/k' 参数使新窗口在运行完命令后保持开启状态
  const newWindowProcess = spawn('cmd.exe', ['/c', 'start', 'cmd.exe', '/k', fullPath], {
    detached: true,
    stdio: 'ignore'
  })

  newWindowProcess.unref() // 允许Node.js主进程退出，而不必等待新窗口进程
}

export { openNewCmdWithFile }
