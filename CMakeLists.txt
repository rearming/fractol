cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 11)

set(Includes
        includes/colors.h
        includes/errors.h
        includes/fractol.h
        includes/key_codes.h
        includes/structs.h
        )

set(libft_includes
        libft/includes)

set(ft_printf_includes
        libft/ft_printf/includes)

set(Sources
        sources/error.c
        sources/fractol.c
        sources/image.c
        sources/init.c
        sources/mandelbrot.c
        sources/hooks.c
        debug/print_params.c
        sources/jumps.c
        sources/opencl_utils.c
        sources/cl_gnl.c)

set(mlx_includes
        /usr/local/include/)

include_directories(includes

        ${Includes}
        ${libft_includes}
        ${ft_printf_includes}
        ${mlx_includes}
        )

link_directories(
        ./libft/
        ./libft/ft_printf/
        /usr/local/lib/)

add_executable(fractol

        ${Sources}
        )

target_link_libraries(fractol

        "ft"
        "ftprintf"
        "mlx"
        "-framework OpenGL"
        "-framework AppKit"
        "-framework OpenCL"
        )