#!/usr/local/bin/bash
cmake -Bbuild
make -Cbuild "$1"
./build/test/"$1"
