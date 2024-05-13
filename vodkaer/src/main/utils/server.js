import { is } from '@electron-toolkit/utils'
const path = require('path')
const express = require('express')

function staticServer(port, dir) {
  const app = express()

  let fullPath
  // 开发环境和生产环境两套路径
  if (is.dev) {
    fullPath = path.resolve('./resources', dir)
  } else {
    fullPath = path.resolve('./resources/app.asar.unpacked', './resources', dir)
  }

  app.use('/', express.static(fullPath))
  app.listen(port, () => {})
}

export default staticServer
