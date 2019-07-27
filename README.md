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
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)
- [Boost](https://www.boost.org/)
  - Boost.DLL
  - Boost.Program_options
- [spdlog](https://github.com/gabime/spdlog)

# Getting sources
Download from github:
```bash
$ git clone https://github.com/BoringStudio/embercore-client.git
```

# CMake configuration
Create a temporary `build` folder and change your working directory to it:
```bash
$ mkdir build
$ cd build/
```

To start using a `Release` configuration:
```bash
$ mkdir release
$ cd release/
$ cmake -DCMAKE_BUILD_TYPE=Release \
    -G "MinGW Makefiles" \
    ../..
```

To use `Debug` configuration:
```bash
$ mkdir debug
$ cd debug/
$ cmake -DCMAKE_BUILD_TYPE=Debug \
    -G "MinGW Makefiles" \
    ../..
```

# CMake configuration flags
If *dependencies* installed into specific directory then you need set `<DEPENDENCY_NAME>_DIR` to directory with installed `<DEPENDENCY_NAME>-config.cmake` or `<DEPENDENCY_NAME>Config.cmake` file (for lua you need set directory to root of lua), for example:
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
# yaml-cpp
-Dyaml-cpp_DIR="D:/dev/yaml-cpp/msvc/CMake"
# Boost
-DBoost_DIR="D:/dev/boost_1_70_0/msvc/lib/cmake/Boost-1.70.0"
-DBoost_NO_BOOST_CMAKE=OFF # For find Boost as config
# spdlog
-Dspdlog_DIR="D:/dev/spdlog/msvc/lib/spdlog/cmake"
```

Set specific path for install:
```bash
-DCMAKE_INSTALL_PREFIX=/your/path/to/install/client
```

Link `SFML` as static library:
```bash
-DSFML_STATIC_LIBRARIES=1
```

Link `Boost` as shared library:
```bash
-DBoost_SHARED_LIBS=1
```

Generate specific project, for example `Visual Studio solution` generator:
```bash
-G "Visual Studio 16"
```

Set specific compiler, for example `Clang`:
```bash
-DCMAKE_C_COMPILER=clang \
-DCMAKE_CXX_COMPILER=clang++
```

# Compiling
To compile client (call from `release` or `debug` directory):
```bash
$ cmake --build .
```

# Installing
To install client to the specified install folder (call from `release` or `debug` directory):
```bash
$ cmake --install .
```

# FAQ
Q: I use MSVC and I have unresolved symbols, and some `mismatch detected for 'RuntimeLibrary': value 'MT_StaticRelease' doesn't match value 'MD_DynamicRelease'` errors on protobuf lib.<br/>
A: You need compile `Protobuf` with cmake define `-Dprotobuf_MSVC_STATIC_RUNTIME=OFF`

Q: When I set cmake generator is "MinGW Makefiles" then i have error:
```bash
  sh.exe was found in your PATH, here:                                
                                                                      
  # some path #                                           
                                                                      
  For MinGW make to work correctly sh.exe must NOT be in your path.   
                                                                      
  Run cmake from a shell that does not have sh.exe in your PATH.
```
A: Two ways to resolve it:<br/>
1. Delete `sh.exe` from `PATH`
2. Try compile one more time (I don't know why, but it works)

Q: If I use `clang-cl` for build `client` then boost cannot find components (by `BoostConfig.cmake`)
A: If you use Boost compiled not `clang-cl` then it try found libs with `clangw\<VERSION>` in file name but not found.
If you use Boost compiled by `MSVC` and want compile *client* by `clang-cl` you need change in `libboost_system-variant-vc*-*.cmake` files:<br/>
from (vc142 in my case)
```cmake
if(Boost_COMPILER AND NOT Boost_COMPILER STREQUAL "vc142")
  _BOOST_SKIPPED("boost_system-vc142-mt-gd-x64-1_70.lib" "vc142, Boost_COMPILER=${Boost_COMPILER}")
  return()
endif()

if(BOOST_DETECTED_TOOLSET AND NOT BOOST_DETECTED_TOOLSET STREQUAL "vc142")
  _BOOST_SKIPPED("boost_system-vc142-mt-gd-x64-1_70.lib" "vc142, detected ${BOOST_DETECTED_TOOLSET}, set Boost_COMPILER to override")
  return()
endif()
```
to<br/>
```cmake
if(Boost_COMPILER AND NOT Boost_COMPILER MATCHES "(vc)|(clangw)")
  _BOOST_SKIPPED("boost_system-vc142-mt-gd-x64-1_70.lib" "vc142, Boost_COMPILER=${Boost_COMPILER}")
  return()
endif()

if(BOOST_DETECTED_TOOLSET AND NOT BOOST_DETECTED_TOOLSET MATCHES "(vc)|(clangw)")
  _BOOST_SKIPPED("boost_system-vc142-mt-gd-x64-1_70.lib" "vc142, detected ${BOOST_DETECTED_TOOLSET}, set Boost_COMPILER to override")
  return()
endif()
```
I don't know why boost try to find only `MSVC` libs