# vision-service-native
vision-service-native 提供了面向 Linux（或 Unix-like）系统的车载视觉业务层封装，对于需要运行Linux系统的ECU
上集成 FaceID 业务提供了良好的服务接口封装，便于快速集成部署
## 快速开始
### 依赖
* vision-ability SDK： [vision-ability-native](http://icode.baidu.com/repos/baidu/iov-bj/vision-ability-native/tree/dev_v1.1.0) -- 提供视觉检测能力接口
* opencv -- 图片处理或模拟 camera
* sqlite -- 人脸底库数据存储
* gtest  -- 单元测试

以上依赖库须根据目标硬件编译后将动态库（静态库）install 到3rd-party 对应路径下；
涉及车控的需要依赖 Tier1提供的车控相关 SDK，若用于调试目的，也可以采用 vision-app/mock/mock-interface 提供的模拟车控 SDK；

### 安装&运行
编译脚本的命令参数如下：
```$xslt
./build.sh [options...]

   -r, --release           Set build type to Release [default]
   -d, --debug             Set build type to Debug
   -t, --target            Set build target, 0-osx-x86_64, 1-linux-x86_64, 2-agl-arm
   -h, --help              show help message
```
示例：
* build for Max OSX
    ```$xslt
    ./build.sh -r -t 0
    ```
* build for Ubuntu
    ```$xslt
    ./build.sh -r -t 1
    ```
* 其他目标平台，需要设置相应的编译工具链

编译时也可以按需选择模块编译，可关闭 vision-app、单元测试、模拟接口，仅编译 vision-service-native 动态库
```$xslt
option(BUILD_APP "build vision_app" ON) # 是否编译 app
option(BUILD_UNIT_TEST "build unit test" ON) # 是否编译单元测试程序，默认打开
option(BUILD_MOCK_INTERFACE "build mock interface lib" ON) # 是否编译模拟接口
```

## 测试
* 单元测试：
    编译后可运行 vision-service-ut 执行单元测试
* 集成测试：
    在 mac 或 ubuntu也可以运行 vision-app，该应用提供 FaceID 的示例应用

