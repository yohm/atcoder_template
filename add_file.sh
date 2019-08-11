#!/bin/bash -eu

read -p "Filename: " F

if [ -f $F.cpp ]; then
  echo "$F.cpp already exists."
  exit
fi

read -p "$F.cpp is being created. ok? (y/N): " yn
if [[ $yn = [yY] ]]; then
  set -x
  cp x.cpp $F.cpp
  echo "add_executable($F $F.cpp)" >> CMakeLists.txt
else
  echo abort
fi

