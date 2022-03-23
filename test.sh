#!/bin/bash
output=`find . -name "*.cpp" -type f -printf '%Ts %p\n' | sort -nr | head -1`
file_name=${output#*\ }

echo "------------------------------------"
echo "file name: $file_name"
echo "------------------------------------"

g++ -g -std=c++17 $file_name
./a.out
