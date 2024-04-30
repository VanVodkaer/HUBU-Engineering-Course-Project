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

  // 选中的列表虚线框 无则加选 有则取消选择
  const selected = ref(undefined)
  function selectOne(id) {
    if (selected.value !== id) {
      selected.value = id
    } else {
      selected.value = undefined
    }
  }
  function clearAllSelected() {
    selected.value = undefined
  }

  function getSelectedAppName() {
    const item = apps.value.find((item) => item.id === selected.value)
    if (item === undefined) {
      return undefined
    } else {
      return item.name
    }
  }

  return { apps, initApps, openApp, selected, selectOne, clearAllSelected, getSelectedAppName }
})
