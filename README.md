# unarc-wrapper

Inspired by https://github.com/Bioruebe/UniExtract2/issues/82#issuecomment-2523977137

## Compilation
Compiled in Anaconda environment, the 64-bit mingw is provided as a package:
> conda install -c msys2 m2w64-toolchain

### 64bit
> g++ -o bin\64bit\unarc.64bit.exe        unarc.cpp\
> g++ -o bin\64bit\unarc.64bit.static.exe unarc.cpp -static

### 32Bit
This one requires mingw 32bit, which is not provided by Anaconda. It can be downloaded from WinLibs project (https://winlibs.com/ MSVCRT runtime, GCC 15.1.0, with POSIX threads + MinGW-w64 12.0.0 (MSVCRT) Win32:
https://github.com/brechtsanders/winlibs_mingw/releases/download/15.1.0posix-12.0.0-msvcrt-r1/winlibs-i686-posix-dwarf-gcc-15.1.0-mingw-w64msvcrt-12.0.0-r1.7z

Add the bin folder to path while in conda activated environment. The compilation is identical:
> set PATH=mingw32\bin;%PATH%\
> g++ -o bin\32bit\unarc.32bit.exe        unarc.cpp\
> g++ -o bin\32bit\unarc.32bit.static.exe unarc.cpp -static

## Runtime requirements
The unarc.exe (and unarc.static.exe) requires external unarc.dll of the same architecture (32/64 bit) in the same folder.
Non-static 32bit version requires additional runtime libraries (libgcc_s_dw2-1.dll ...)

## Usage
As stated on source comment. App expects to have exactly 7 arguments, so you'll need to provide empty quotes if you do not have that many.

### List archive content
> unarc.exe l setup-1.bin "" "" "" ""

### Extract the content from an archive
> unarc.exe unarc.dll x -dpout -wout setup-1.bin "" ""

### Extract the content from an archive with custom options
> unarc.exe unarc.dll x -dpout -wout -cfgarc.ini setup-1.bin ""

### Extract the content from an archive with custom options overwriting existing files
> unarc.exe unarc.dll x -o+ -dpout -wout -cfgarc.ini setup-1.bin

