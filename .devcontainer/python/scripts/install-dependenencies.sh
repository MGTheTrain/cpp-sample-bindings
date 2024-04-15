#!/bin/bash

set -euo pipefail

apt-get update
apt-get install -y cmake python3 python3-pip
pip3 install clang-format cpplint

cd /tmp/
# vcpkg
rm -rf vcpkg
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
# emscripten SDK
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest-upstream
./emsdk activate latest-upstream