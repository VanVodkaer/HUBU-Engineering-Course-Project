import { defineStore } from 'pinia'
import { ref } from 'vue'

export const useDesktopStore = defineStore('desktop', () => {
  // {id:ID号,name:软件名称,iconSrc:图标地址,command:启动命令}
  const apps = ref([])

  // 请求软件列表信息 initApps
  async function initApps() {
    apps.value = await window.api.initApps()
  }

  // 处理软件打开请求 openApps
  async function openApp(command) {
    window.api.openApp(command)
  }

  return { apps, initApps, openApp }
})
