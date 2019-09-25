#!/bin/bash -eu

if [ $# -eq 0 ]; then
  echo "no argument is given"
  exit
fi

for F in $@
do
  if [ -f $F.cpp ]; then
  echo "$F.cpp already exists."
    exit
  fi
  set -x
  cp x.cpp $F.cpp
  echo "add_executable($F $F.cpp)" >> CMakeLists.txt
  set +x
done

