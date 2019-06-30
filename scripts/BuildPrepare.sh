#!/bin/bash

BASEDIR=$(dirname "$0")

## Prepare Lua directory
LUA_DIR="$BASEDIR/../extlibs/libs-lua"

if [ ! -d "$LUA_DIR/include/" ]
then
    mkdir $LUA_DIR/include/
fi

# Clear include folder from previous files
rm -rf $LUA_DIR/include/*

if [ ! -d "$LUA_DIR/lib/" ]
then
    mkdir $LUA_DIR/lib/
fi

# Create release folder
if [ ! -d "$LUA_DIR/lib/release/" ]
then
    mkdir $LUA_DIR/lib/release/
fi

# Create release include folder
if [ ! -d "$LUA_DIR/lib/release/include/" ]
then
    mkdir $LUA_DIR/lib/release/include/
fi

# Create debug folder
if [ ! -d "$LUA_DIR/lib/debug/" ]
then
    mkdir $LUA_DIR/lib/debug/
fi

# Create debug include folder
if [ ! -d "$LUA_DIR/lib/debug/include/" ]
then
    mkdir $LUA_DIR/lib/debug/include/
fi

rm -rf $LUA_DIR/lib/release/include/*
rm -rf $LUA_DIR/lib/debug/include/*

# Copy all headers to includes folder
find $LUA_DIR/ -type f | grep -i ".h$" | while read -r header ; do
    cp $header $LUA_DIR/include/
    cp $header $LUA_DIR/lib/release/include/
    cp $header $LUA_DIR/lib/debug/include/
done

# Create CMake project
if [ -f "$LUA_DIR/CMakeLists.txt" ]
then
    rm $LUA_DIR/CMakeLists.txt
fi

cp $BASEDIR/LuaBuild.cmake $LUA_DIR/CMakeLists.txt

## Prepare SFML directory
SFML_DIR="$BASEDIR/../extlibs/libs-SFML"

if [ ! -d "$BASEDIR/../bin" ]
then
    mkdir $BASEDIR/../bin
fi

cp -a $SFML_DIR/extlibs/bin/x64/. $BASEDIR/../bin/