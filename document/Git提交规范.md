# 小组项目 Git 提交规范

## 设置项目

1. 安装 Git 软件，设置个人 Git 信息  

   > git config --global user.name "你的用户名"    
   > git config --global user.email 你的邮箱

2. 拉取项目

   > git clone https://github.com/VanVodkaer/HUBU-Engineering-Course-Project.git

   此时你应该得到了一个名为 `HUBU-Engineering-Course-Project` 的文件夹  

3. 在里面创建一个新的文件夹 以你的名称命名这里以 `example`为例（请不要包含中文或空格）

4. 新建一个分支，并进行一次commit

    > git branch example
    > git add .
    > git commit -m "init example"
    > git push -u origin example

5. 这样你就创建好了你的开发分支并完成了一次提交，接下来请在自己的分支自己的文件夹中进行开发

## 提交更改

1. 暂存文件

> git add .

2. 新增一条commit

> git commit -m "Commit注释"

3. 推送到远程仓库

> git push -u origin example

## .gitignore 文件

请在你的目录下新建一个 `.gitignore` 文件，并在其中添加你不希望被提交到仓库的内容（文件/文件夹），每个文件/文件夹名写一行即可


# 什么不能做：
## 请不要在未经允许的情况下直接向main分支合并！

