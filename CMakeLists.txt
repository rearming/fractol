cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 11)

set(Includes
        includes/colors.h
        includes/errors.h
        includes/fractol.h
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
		sources/terminal/term_processor.c

        sources/utils/error.c
        sources/utils/image.c
        sources/utils/init.c
        sources/utils/complex_math.c
        sources/utils/bresenham.c
        sources/utils/rotation.c

        sources/fractals/mandelbrot.c

        sources/fractals/jumps.c
        sources/fractals/julia.c
        sources/fractals/triangle.c
		sources/hooks/hooks_triangle.c
		sources/utils/screen_info.c sources/utils/exit_clean.c)

if (__linux__)
	set(mlx_includes
        ./minilibx/minilibx_linux
		/usr/local/cuda-10.1/targets/x86_64-linux/include/
		/usr/include/X11/
		)

	set(X11_lib_dirs
			/usr/lib/X11
			/usr/X11/lib
			)

	set(X11_libs
			"OpenCL"
			"mlx_Linux"
			"Xext"
			"X11"
			)

	message(hello, Linux)

else()
	set(mlx_includes
			#./minilibx/minilibx_mac
			)

	message(hello, Mac)
endif()

include_directories(includes

        ${Includes}
        ${libft_includes}
        ${ft_printf_includes}
		${mlx_includes}
        )

link_directories(

        ./libft/
        ./libft/ft_printf/
		${mlx_includes}
		${X11_lib_dirs}
)

add_executable(fractol

        ${Sources}
        )

target_link_libraries(fractol

		"m"
        "ftprintf"
		"ft"
        "mlx"
        "-framework OpenGL"
        "-framework AppKit"
        "-framework OpenCL"
		${X11_libs}
)



