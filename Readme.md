C++ 11 Features

- Move Semantics

- Variadic Templates

- Initializer Lists

- Auto Keyword

- Lambda Expressions

- Null Pointer

- const expressions

- range-based for loop

- Smart Pointers

C++ 17 Major Release Features
- Standard file system within the Standard Library

- Parallel implementations of string view

- Parallel implementations of many Standar library algorithms 

- Inline variables

Compiler

    =================================================
 a.hpp          b.hpp     c.hpp       d.hpp
        a.cpp       b.cpp       c.cpp

                Preprocessor

        d.hpp       c.hpp   d.hpp
        b.hpp       b.hpp   c.hpp
        a.hpp       b.cpp   b.hpp
        a.cpp               c.cpp

                  Compiler

        a.o         b.o     c.o 

                    Linker

                    a.exe

    =================================================

Make

GNU Make and `Makefile`

```
make build
make clean
```

CMake and `CMakeLists.txt`
- [See cmake tutorial](https://cmake.org/cmake-tutorial/)

Requirements
- g++, gdb, make

On Linux
```
sudo apt update
sudo apt install build-essential gdb
```

On Windows
- Install [MinGW](http://www.mingw.org/)
- Install [VSCode](https://code.visualstudio.com/Download)
- Install `C/C++ Extension`, and  `clang-format` in VSCode

Debug
- [GDB](https://www.gnu.org/software/gdb/)
- [LLDB](https://lldb.llvm.org/)
- See [this video](https://youtu.be/NnVIq_z-AEI)
