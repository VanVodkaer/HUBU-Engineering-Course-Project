import { contextBridge, ipcRenderer } from 'electron'
import { electronAPI } from '@electron-toolkit/preload'

// 自定义 API 供渲染进程使用
const api = {
  // 请求软件列表信息
  async initApps() {
    // 调用主进程的 'initApps' 通道并等待响应
    return await ipcRenderer.invoke('initApps')
  },

  // 处理软件打开请求
  openApp(command) {
    // 向主进程发送 'openApp' 消息
    ipcRenderer.send('openApp', command)
  }
}

// 如果启用了上下文隔离，使用 `contextBridge` API
// 向渲染进程暴露 Electron API，
// 否则直接添加到 DOM 的全局对象。
if (process.contextIsolated) {
  try {
    // 在全局 window 对象上暴露 'electron' API
    contextBridge.exposeInMainWorld('electron', electronAPI)
    // 在全局 window 对象上暴露 'api' 对象
    contextBridge.exposeInMainWorld('api', api)
  } catch (error) {
    // 如果暴露 API 过程中出现错误，输出错误信息
    console.error(error)
  }
} else {
  // 如果未启用上下文隔离，则将 API 直接挂载到 window 对象上
  window.electron = electronAPI
  window.api = api
}
