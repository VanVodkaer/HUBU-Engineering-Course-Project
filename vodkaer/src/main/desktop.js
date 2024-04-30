const apps = [
  { id: 1, name: '软件1', iconSrc: '../../resources/icon.png', command: '启动命令1' },
  { id: 2, name: '软件2', iconSrc: '../../resources/icon.png', command: '启动命令2' }
]

function initApps() {
  return apps
}

function openApp(command) {
  console.log(command)
}

export { initApps, openApp }
