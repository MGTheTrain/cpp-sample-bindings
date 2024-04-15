#!/bin/bash

set -euo pipefail

apt-get update
apt-get install -y cmake python3 python3-pip pkg-config
pip3 install clang-format cpplint

cd /tmp/
# vcpkg
rm -rf vcpkg
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
