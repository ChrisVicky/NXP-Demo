# NXP 实习 第七组 DOC

1. [配置`vscode`调试环境](#配置`vscode`调试环境)
2. [`clion`配置](#`clion`配置)
3. [`GUI-Guider`生成使用`v9`代码](`GUI-Guider`生成使用`v9`代码)
4. [嵌入`v9`代码并修改相应`API`成功编译](嵌入`v9`代码并修改相应`API`成功编译)

## 配置`vscode`调试环境
1. 下载代码
```bash
git clone xxx
```

2. 手动编译：检查缺失环境，例如`SDL2`之类
```bash
# Makefile 存在
make
# 只有 CMakeLists.txt
mkdir build && cd build
cmake ..
make
```

3. 手动编译通过后，在`vscode`中下载如下插件

<center>
    <img style="border-radius: 0.3125em;box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);"
        src="img/image_2023-05-10-10-10-55.png"><br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;display: inline-block;color: #999;padding: 2px;">vscode插件</div>
</center>

4. 编辑`.vscode/tasks.json`以及`.vscode/launch.json`等文件加入调试指令
    * `tasks.json`
    ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "type": "shell",
               "label": "Build",
               "command": "make",
               "options": {
                   "cwd": "${workspaceFolder}"
               },
               "presentation": {
                   "echo": true,
                   "reveal": "always",
                   "focus": false,
                   "panel": "shared"
               },
               "problemMatcher": {
                   "owner": "cpp",
                   "fileLocation": [
                       "relative",
                       "${workspaceFolder}"
                   ],
                   "pattern": {
                       "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                       "file": 1,
                       "line": 2,
                       "column": 3,
                       "severity": 4,
                       "message": 5
                   }
               },
               "group": "build"
           },
       ]
   }
    ```
    * `launch.json`
    ```json
    {
      "version": "0.2.0",
      "configurations": [
        {
          "name": "g++ build and debug active file",
          "type": "cppdbg",
          "request": "launch",
          // built by `make` command, specified by `Makefile`
          "program": "${workspaceFolder}/build/bin/demo",
          "args": [],
          "stopAtEntry": false,
          "cwd": "${workspaceFolder}",
          "environment": [],
          "externalConsole": false,
          "MIMode": "gdb",
          "setupCommands": [
            {
              "description": "Enable pretty-printing for gdb",
              "text": "-enable-pretty-printing",
              "ignoreFailures": true
            }
          ],
          "preLaunchTask": "Build"
        }
      ]
    }
    ```

## `GUI-Guider`生成使用`v9`代码
## 嵌入`v9`代码并修改相应`API`成功编译




