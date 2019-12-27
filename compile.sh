#!/bin/bash

CLANG=$(find /usr /home -type f -name clang 2>/dev/null)
if [[ "$CLANG" == "" ]]; then
  echo "can't find clang compiler! please, instatll it!"
  exit 1
fi

if [[ "$OSTYPE" == "linux-gnu" ]]; then
  cd minilibx/minilibx_linux || echo "can't go to minilibx_linux directory!"
  make
  cd ../..
else
  cd minilibx/minilibx_mac || echo "can't go to minilibx_mac directory!"
  make
  cd ../..
fi

if [[ ! -f "libft/Makefile" ]]; then
  git submodule init
  git submodule update --merge --remote
fi
cd libft || echo "can't find libft directory!"
make
cd ..

mkdir build
cd build || echo "can't make build directory!"
cmake -D CMAKE_C_COMPILER="$CLANG" DCMAKE_BUILD_TYPE=Release ..
make fractol -j 4
mv fractol ..
