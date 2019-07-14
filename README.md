# Description
Source code of *Embercore* game client

# Dependencies
To build this project you need install:
- [SFML](https://github.com/SFML/SFML)
- [Lua](https://www.lua.org/)
- [Sol2](https://github.com/ThePhD/sol2)
- [Protobuf](https://github.com/protocolbuffers/protobuf)
- [EnTT](https://github.com/skypjack/entt)
- [EmbercoreProtocol](https://github.com/BoringStudio/embercore-protocol)

# Getting sources
Download from github:
```bash
$ git clone https://github.com/BoringStudio/embercore-client.git
```

# CMake configuration
Create a temporary *build* folder and change your working directory to it:
```bash
$ mkdir build
$ cd build/
```

To start using a *Release* configuration:
```bash
$ mkdir release
$ cd release/
$ cmake -DCMAKE_BUILD_TYPE=Release \
    -G "MinGW Makefiles" \
    -DCMAKE_INSTALL_PREFIX=/your/path/to/install/client \ 
    ../..
```

To use *Debug* configuration:
```bash
$ mkdir debug
$ cd debug/
$ cmake -DCMAKE_BUILD_TYPE=Debug \
    -G "MinGW Makefiles" \
    -DCMAKE_INSTALL_PREFIX=/your/path/to/install/client \ 
    ../..
```

# CMake configuration flags
If *dependencies* installed into specific directory then you need set *<DEPENDENCY_NAME>_DIR* to directory with installed *<DEPENDENCY_NAME>-config.cmake* or *<DEPENDENCY_NAME>Config.cmake* file (for lua you need set directory to root of lua), for example:
```bash
# SFML
-DSFML_DIR="D:/dev/SFML-2.5.1/clang/lib/cmake/SFML"
# Protobuf
-DProtobuf_DIR="D:/dev/protobuf/mingw/lib/cmake/protobuf"
# Lua
-DLUA_DIR="D:/dev/lua/mingw"
# EmbercoreProtocol
-DEmbercoreProtocol_DIR="D:/dev/embercore-protocol/clang/cmake"
# EnTT
-DEnTT_DIR="D:/dev/EnTT/cmake"
# Sol2
-Dsol2_DIR="D:/dev/sol2/lib/cmake/sol2"
```

Generate specific project, for example *Visual Studio solution* generator:
```bash
-G "Visual Studio 16"
```

Set specific compiler, for example *Clang*:
```bash
-DCMAKE_C_COMPILER=clang \
-DCMAKE_CXX_COMPILER=clang++
```

# Compiling
To compile protocol (call from *release* or *debug* directory):
```bash
$ cmake --build .
```

# Installing
To install protocol to the specified install folder (call from *release* or *debug* directory):
```bash
$ cmake --install .
```