#!/bin/bash

set -euo pipefail

apt-get update
apt-get install -y cmake python3 python3-pip pkg-config portaudio19-dev nasm
pip3 install clang-format cpplint jinja2

cd /tmp/
# vcpkg
rm -rf vcpkg
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
