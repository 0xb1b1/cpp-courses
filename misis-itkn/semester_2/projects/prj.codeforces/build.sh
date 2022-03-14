#!/bin/sh
build_dir='out/build'

mkdir -p $build_dir
cmake -S . -B $build_dir
cd $build_dir
make

