// console.log(__dirname)

const appinfo = [
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

function getAppsInfo() {
  return appinfo
}

export { getAppsInfo }
