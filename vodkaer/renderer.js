const { spawn } = require("child_process");
let childProcess;

document.getElementById("input").addEventListener("keydown", function (event) {
  if (event.key === "Enter") {
    const command = event.target.value;
    const args = command.split(" ").filter((arg) => arg); // 将命令行分解成命令和参数
    const cmd = args.shift(); // 分离命令和参数

    event.target.value = ""; // 清空输入框

    // 如果没有正在运行的进程，则创建一个
    if (!childProcess) {
      childProcess = spawn(cmd, args, { shell: true });

      childProcess.stdout.on("data", function (data) {
        const output = document.getElementById("output");
        output.textContent += data.toString();
        output.scrollTop = output.scrollHeight; // 滚动到底部
      });

      childProcess.stderr.on("data", function (data) {
        const output = document.getElementById("output");
        output.textContent += `ERROR: ${data.toString()}`;
        output.scrollTop = output.scrollHeight;
      });

      childProcess.on("exit", function () {
        childProcess = null; // 当进程退出时，重置变量
      });

      childProcess.on("error", function (err) {
        console.log("Failed to start subprocess.");
      });
    }
  }
});
