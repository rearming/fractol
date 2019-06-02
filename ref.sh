rm fractol
cp cmake-build-debug/fractol .
valgrind --leak-check=full ./fractol mandelbrot
