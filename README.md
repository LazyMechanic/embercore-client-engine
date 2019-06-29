Before building need run next script:
```
./scripts/BuildPrepare.sh
```

Building the project:
```
mkdir build
cd build/
cmake ..
cmake --build .
```

If you need using specific compiler then use (clang for example):
```
cmake .. -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
```

If you need using specific cmake generator then use:
```
# For mingw
cmake .. -G "MinGW Makefiles"

# For Visual Studio 2019
cmake .. -G "Visual Studio 16 2019"

# etc.
```