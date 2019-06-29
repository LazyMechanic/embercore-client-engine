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

# Copy all headers to include folder
find $LUA_DIR/ -type f | grep -i ".h$" | while read -r header ; do
    cp $header $LUA_DIR/include/
done

#find $LUA_DIR/ -type f | grep -i ".h$" | xargs -i cp -a {} $LUA_DIR/include/

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