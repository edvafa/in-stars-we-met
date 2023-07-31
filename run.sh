#!/bin/sh

mkdir -p bin

export LD_LIBRARY_PATH=$PWD/bin
./lib.sh
cc src/main.c -o bin/game -lraylib
bin/game

rm -r bin/*
rmdir bin