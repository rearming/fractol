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

set(Libft_includes
        libft/includes)

set(Sources
        sources/error.c
        sources/fractol.c
        sources/image.c
        sources/init.c
        sources/mandelbrot.c
        )

set(mlx_includes
        /usr/local/include/)

include_directories(includes

        ${Includes}
        ${Libft_includes}
        ${mlx_includes}
        )

link_directories(
        ./libft/
        /usr/local/lib/)

add_executable(fractol

        ${Sources}
        )

target_link_libraries(fractol

        "ft"
        "mlx"
        "-framework OpenGL"
        "-framework AppKit"
        )