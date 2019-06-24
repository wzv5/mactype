MacType
========================

Better font rendering for Windows.

详细介绍请移步：<https://github.com/snowie2000/mactype>

相比官方仓库，我把所有依赖项都通过 vcpkg 和 git 子模块 来解决，所以做到了直接拉取源码就能编译，不用手动编译依赖项。

注意：本项目也是我的个人实验环境，代码可能会频繁修改，并可能存在 force push 的情况，但会保证每次推送都是直接可编译的代码。

如何编译
-------

1. 安装 vcpkg：<https://github.com/microsoft/vcpkg>

2. 安装 vcpkg integration：

``` text
vcpkg integrate install
```

3. 通过 vcpkg 安装依赖项：

``` text
vcpkg install freetype:x64-windows-static freetype:x86-windows-static
```

4. 拉取源码：

``` text
git clone --recursive https://github.com/wzv5/mactype
```

5. 如果拉取源码时忘记使用 `--recursive` 参数，则需要手动拉取子模块：

``` text
git submodule update --init --recursive
```
6. 使用 VS2019 打开 `gdipp.sln`，其中包含以下项目：

* EasyHookDll：依赖项，编译为 `EasyHK32.dll` 和 `EasyHK64.dll`
* IniParser：依赖项
* wow64ext：依赖项
* MacType：主项目，编译为 `MacType.Core.dll` 和 `MacType64.Core.dll`
* run：用于测试和观察渲染结果的窗口程序，C++ 原生窗口程序
* winformrun：用于测试和观察渲染结果的窗口程序，C# winform 程序

所有项目的 Debug 和 Release、win32 和 x64 都已配置好，把 run 和 winformrun 作为启动项目，直接运行就能看到效果。
