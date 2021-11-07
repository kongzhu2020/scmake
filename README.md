# 本文介绍如何使用cmake编译C/C++工程

## 官方文档
### https://cmake.org/cmake/help/latest/index.html

## 常用命令
$ cmake -B <build dir>
$ cmake --build <build dir>
$ cmake --build -DUSE_MATH=OFF <build dir>

## 自定义编译选项 
### 1. 打开：XXXConfig.h.in
### 2. 添加：#cmakedefine USE_SMATH
### 3. 执行：cmake -DUSE_SMATH=OFF -B build
### 4. 查看：查看build目录下XXXConfig.h文件，编译选项是否被修改
### 5. 清理：命令行修改编译选项后清理掉编译缓存，重新执行cmake命令


## 交叉编译
### 1. 文档：https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html
### 2. 执行：j$ cmake .. -DCMAKE_SYSTEM_NAME=Android -DCMAKE_SYSTEM_VERSION=21 -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a -DCMAKE_ANDROID_NDK=/Users/xiaxing/Library/Android/ndk/android-ndk-r18b/ -DCMAKE_ANDROID_STL_TYPE=c++_static

