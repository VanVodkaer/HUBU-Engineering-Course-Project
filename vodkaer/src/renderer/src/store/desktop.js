import { defineStore } from 'pinia'
import { ref } from 'vue'

export const useDesktopStore = defineStore('desktop', () => {
  // {id:ID号,name:软件名称,iconSrc:图标地址,command:启动命令}
  const apps = ref([])

  function initApps() {
    apps.value = [
      { id: 1, name: '软件1', iconSrc: './temp/1.png', command: 'command1' },
      { id: 2, name: '软件2', iconSrc: './temp/2.png', command: 'command2' }
    ]
  }

  return { apps, initApps }
})
