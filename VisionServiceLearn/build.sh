#!/usr/bin/env bash

echo "print ndk home"
echo $NDK_HOME
# NDK
export ANDROID_NDK=~/Documents/ndk/android-ndk-r17c

if [ "$NDK_HOME" = "" ]; then
  if [ "$ANDROID_NDK" = "" ]; then
    echo "ERROR: Please set ANDROID_NDK or NDK_HOME environment"
    exit 1
  else
    NDK_HOME="$ANDROID_NDK"
  fi
fi
echo $NDK_HOME

# Android编译工具链

ANDROID_TOOLCHAIN=$NDK_HOME/build/cmake/android.toolchain.cmake

# 声明一个帮助方法
show_help() {
  echo "Usage: $0 [option...]" >&2
  echo
  echo "   -r, --release           Set build type to Release [default]"
  echo "   -d, --debug             Set build type to Debug"
  echo "   --RelWithDebInfo        Set build type to RelWithDebInfo"
  echo "   -t, --target            Set build target, 0-osx-x86_64, 1-linux-x86_64, 2-agl-arm"
  echo "   -h, --help              show help message"
  echo
}

# default setting
TARGET_INDEX="0"
BUILD_TYPE="release"
# shell 脚本的参数解析：
# $0	当前脚本的文件名
echo "当前脚本的文件名：$0"
# 传递给脚本或函数的参数个数。
echo "传递给脚本或函数的参数：$#"
# 传递给脚本或函数的所有参数。$*
echo "传递给脚本或函数的所有参数：$*"
# 上个命令的退出状态，或函数的返回值。$?
echo "上个命令的退出状态：$?"
# 当前Shell进程ID。对于 Shell 脚本，就是这些脚本所在的进程ID。$$
echo "当前Shell进程ID：$$"

# 传递给脚本或函数的参数。n 是一个数字，表示第几个参数。例如，第一个参数是$1，第二个参数是$2。
echo "第一个参数是：$1"
echo "第二个参数是：$2"
echo "第三个参数是：$3"

while [ $# != 0 ]; do
  case "$1" in
  # 设置编译的target为第二个参数
  -t)
    TARGET_INDEX=$2
    # shift命令用于对参数的移动(左移)，
    # 通常用于在不知道传入参数个数的情况下依次遍历每个参数然后进行相应处理
    # （常见于Linux中各种程序的启动脚本） 。
    shift
    ;;
  --target)
    TARGET_INDEX=$2
    shift
    ;;
  -r)
    BUILD_TYPE="release"
    ;;
  --release)
    BUILD_TYPE="release"
    ;;
  -d)
    BUILD_TYPE="debug"
    ;;
  --debug)
    BUILD_TYPE="debug"
    ;;
  --RelWithDebInfo)
    BUILD_TYPE="RelWithDebInfo"
    ;;
  -h)
    show_help
    exit 1
    ;;
  --help)
    show_help
    exit 1
    ;;
  *) ;;

  esac
  shift
done

echo "=================================编译配置===================================="
echo "编译平台 : $TARGET_INDEX  , 编译类型 : $BUILD_TYPE "
case "$TARGET_INDEX" in
0)
  TARGET="osx-x86_64"
  ;;
1)
  TARGET="android-armeabi-v7a"
  SYSTEM_TYPE="armeabi-v7a"
  ;;
2)
  TARGET="android-arm64-v8a"
  SYSTEM_TYPE="arm64-v8a"
  ;;
3)
  TARGET="android-x86_64"
  SYSTEM_TYPE="x86_64"
  ;;
4)
  TARGET="android-x86"
  SYSTEM_TYPE="x86"
  ;;
*)
  TARGET="osx-x86_64"
  ;;
esac

echo "==============编译平台 : $TARGET  , 编译类型 : $BUILD_TYPE ============="

if [ ! -d build ]; then
  mkdir -p build
fi

cd build

# 根据编译平台和编译类型设置编译的目录
BUILD_DIR="$TARGET-$BUILD_TYPE"

# 创建对应的编译目录
if [ -d $BUILD_DIR ]; then
  rm -rf $BUILD_DIR
fi
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# 开始编译Mac平台上的可执行程序
if [ "$TARGET" = "osx-x86_64" ]; then
  echo "===============cmake 开始编译osx-x86_64平台可执行程序===================="
  # DCMAKE_BUILD_TYPE显示指定Cmake编译的类型：https://www.jianshu.com/p/0bef91a67860
  cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DVISION_TARGET_OS=osx \
    -DVISION_TARGET_ARCH=x86_64 \
    ../..
elif [ "$TARGET" = "linux-x86_64" ]; then
  echo "cmake target: linux-x86_64"
  cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DVISION_TARGET_OS=linux \
    -DVISION_TARGET_ARCH=x86_64 \
    ../..
elif [ "$TARGET" = "android-arm64-v8a" ]; then
  echo "===============cmake 开始编译android-arm64-v8a平台可执行程序===================="
  #
  cmake -DANDROID_ABI=arm64-v8a \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DVISION_TARGET_OS=android \
    -DVISION_TARGET_ARCH=arm64-v8a \
    -DVISION_OSX=OFF \
    -DVISION_ANDROID=ON \
    -DVISION_TARGET_TYPE=SHARED \
    -DCMAKE_CXX_FLAGS="-std=c++11 -frtti -fexceptions" \
    -DANDROID_PLATFORM=android-23 \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN \
    -DANDROID_ARM_NEON=ON \
    ../..
  #  -DANDROID_STL=c++_shared \
fi

# 执行完成上面的语句之后。会输出输出一系列的log信息
# 同时在build/编译平台目录下生成了三个文件CMakeCache.txt、Makefile、cmake_install.cmake和一个文件夹CmakeFiles
#
#
# 然后执行下面语句 启动4个线程进行编译
make -j 4
echo "make finished!"

make install
echo "install finished!"
cd -
exit 0
