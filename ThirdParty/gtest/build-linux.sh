#!/bin/sh

mkdir -p build
cd build
cmake /usr/src/gtest -DCMAKE_BUILD_TYPE=Release
make -j8
