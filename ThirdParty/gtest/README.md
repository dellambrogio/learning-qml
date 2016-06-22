# About
Google Test is a unit testing library for the C++ programming language, based on the xUnit architecture.It can be compiled for a variety of POSIX and Windows platforms, allowing unit-testing of 'C' sources as well as C++ with minimal source modification. The tests themselves could be run one at a time, or even be called to run all at once. This makes the debugging process very specific and caters to the need of many programmers and coders alike.

https://github.com/google/googletest

# Install

## Linux
On debian-based system
```bash
sudo apt-get install libgtest-dev
cd /path/to/ThirdParty/gtest
mkdir -p build
cd build
cmake /usr/src/gtest -DCMAKE_BUILD_TYPE=Release
make -j8
```
