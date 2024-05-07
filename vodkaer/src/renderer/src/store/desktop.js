import { defineStore } from 'pinia'
import { ref } from 'vue'

export const useDesktopStore = defineStore('desktop', () => {
  // {id:ID号,name:软件名称,iconSrc:图标地址,command:启动命令}
  const apps = ref([])
  const resUrl = ref('')

  // 请求软件列表信息 initApps

  async function initApps() {
    apps.value = [
      {
        id: 1,
        name: '计算器',
        iconSrc: 'CalculatorProgram.png',
        command: 'helloworld.exe'
      },
      {
        id: 2,
        name: '温度转换',
        iconSrc: 'TemperatureConverter.png',
        command: '启动命令2'
      },
      {
        id: 3,
        name: '质数检测',
        iconSrc: 'PrimeNumberChecker.png',
        command: '启动命令2'
      },
      {
        id: 4,
        name: '斐波那契数列生成',
        iconSrc: 'FibonacciSequenceGenerator.png',
        command: '启动命令2'
      },
      {
        id: 5,
        name: '猜数游戏',
        iconSrc: 'GuessTheNumberGame.png',
        command: '启动命令2'
      }
    ]
    resUrl.value = await window.api.getResUrl()
  }

  // 处理软件打开请求 openApps
  function openApp(command) {
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

  return {
    apps,
    resUrl,
    initApps,
    openApp,
    selected,
    selectOne,
    clearAllSelected,
    getSelectedAppName
  }
})
