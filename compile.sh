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
cmake -DCMAKE_BUILD_TYPE=Release ..
make fractol -j 4
mv fractol ..
