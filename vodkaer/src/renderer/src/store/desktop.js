import { defineStore } from 'pinia'
import { ref } from 'vue'

// {name:软件名称,iconSrc:图标地址}
const apps = ref({})

export const useDesktopStore = defineStore('desktop', {
  apps
})
