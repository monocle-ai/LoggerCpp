#!/bin/bash 
echo "Generating Protobuf Files"
cd ../external/fmt
mkdir build 
cd build 
cmake -DCMAKE_BUILD_TYPE=debug .. 
cd build 
cmake .. 
cmake --build .
echo "Finish building project"
pause