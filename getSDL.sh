#!/bin/bash

SDL2_VERSION="2.26.5"

pushd SDL

wget https://github.com/libsdl-org/SDL/releases/download/release-2.26.5/SDL2-${SDL2_VERSION}.zip
unzip -q SDL2-${SDL2_VERSION}.zip
mv SDL2-${SDL2_VERSION}/include include
ln -s . include/SDL2
rm SDL2-${SDL2_VERSION}.zip
rm -r SDL2-${SDL2_VERSION}

popd
