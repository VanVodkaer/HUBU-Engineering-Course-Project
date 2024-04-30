const { spawn } = require('child_process')
const path = require('path')

console.log(__dirname)

// 替换'exefile.exe'为你的exe文件路径
const child = spawn(path.join(__dirname, 'bin', 'exefile.exe'))

// 获取从exe输出的数据
child.stdout.on('data', (data) => {
  console.log(`子进程输出: ${data}`)
})

// 如果exe写入到stderr
child.stderr.on('data', (data) => {
  console.error(`子进程错误输出: ${data}`)
})

// 子进程退出事件
child.on('close', (code) => {
  console.log(`子进程退出码: ${code}`)
})

// 向exe发送输入
child.stdin.write('你要发送的输入数据')
child.stdin.end() // 结束输入，如果你的exe是等待输入的，不调用end可能会导致exe挂起不退出。
