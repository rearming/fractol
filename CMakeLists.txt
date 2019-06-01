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
        debug/print_params.c

        sources/fractol.c

        sources/hooks/hooks.c
        sources/hooks/hooks_julia.c
        sources/hooks/hooks_mandelbrot.c

        sources/open_cl/opencl_utils.c
        sources/open_cl/cl_gnl.c
        sources/open_cl/cl_render.c
        sources/open_cl/clean_opencl.c

        sources/terminal/terminal.c
        sources/terminal/parse_term_input.c
        sources/terminal/term_string_utils.c

        sources/utils/error.c
        sources/utils/image.c
        sources/utils/init.c
        sources/utils/complex_math.c
        sources/utils/bresenham.c
        sources/utils/rotation.c

        sources/fractals/mandelbrot.c

        sources/fractals/jumps.c
        sources/fractals/julia.c
        sources/fractals/triangle.c sources/hooks/hooks_triangle.c sources/utils/screen_info.c)

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