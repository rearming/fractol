if [[ "$OSTYPE" == "linux-gnu" ]]; then
  cd minilibx/minilibx_linux || echo "can't go to minilibx_linux directory!"
  make
  cd ../..
else
  cd minilibx/minilibx_mac || echo "can't go to minilibx_mac directory!"
  make
  cd ../..
fi
mkdir build
cd build || echo "can't make build directory!"
cmake -DCMAKE_BUILD_TYPE=Release ..
make fractol
mv fractol ..
