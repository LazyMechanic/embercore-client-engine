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
- [cxxopts](https://github.com/jarro2783/cxxopts)
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)

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
    ../..
```

To use *Debug* configuration:
```bash
$ mkdir debug
$ cd debug/
$ cmake -DCMAKE_BUILD_TYPE=Debug \
    -G "MinGW Makefiles" \
    ../..
```

# CMake configuration flags
If *dependencies* installed into specific directory then you need set *<DEPENDENCY_NAME>_DIR* to directory with installed *<DEPENDENCY_NAME>-config.cmake* or *<DEPENDENCY_NAME>Config.cmake* file (for lua you need set directory to root of lua), for example:
```bash
# SFML
-DSFML_DIR="D:/dev/SFML-2.5.1/msvc/lib/cmake/SFML"
# Protobuf
-DProtobuf_DIR="D:/dev/protobuf/msvc/lib/cmake/protobuf"
# Lua
-DLUA_DIR="D:/dev/lua/mingw"
# EmbercoreProtocol
-DEmbercoreProtocol_DIR="D:/dev/embercore-protocol/msvc/cmake"
# EnTT
-DEnTT_DIR="D:/dev/EnTT/cmake"
# Sol2
-Dsol2_DIR="D:/dev/sol2/lib/cmake/sol2"
# cxxopts
-Dcxxopts_DIR="D:/dev/cxxopts/lib/cmake/cxxopts"
# yaml-cpp
-Dyaml-cpp_DIR="D:/dev/yaml-cpp/msvc/CMake"
```

Set specific path for install:
```bash
-DCMAKE_INSTALL_PREFIX=/your/path/to/install/client
```

Link *SFML* as static library:
```bash
-DSFML_STATIC_LIBRARIES=1
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

# FAQ
Q: I use MSVC and I have unresolved symbols, and some *mismatch detected for 'RuntimeLibrary': value 'MT_StaticRelease' doesn't match value 'MD_DynamicRelease'* errors on protobuf lib.<br/>
A: You need compile *Protobuf* with cmake define *-Dprotobuf_MSVC_STATIC_RUNTIME=OFF*

Q: When I set cmake generator is "MinGW Makefiles" then i have error:
```bash
  sh.exe was found in your PATH, here:                                
                                                                      
  # some path #                                           
                                                                      
  For MinGW make to work correctly sh.exe must NOT be in your path.   
                                                                      
  Run cmake from a shell that does not have sh.exe in your PATH.
```
A: Two ways to resolve it:<br/>
1. Delete *sh.exe* from *PATH*
2. Try compile one more time (I don't know why, but it works)