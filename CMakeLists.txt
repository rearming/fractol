cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 11)

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
		sources/utils/screen_info.c
		sources/utils/exit_clean.c)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(mlx_includes
        ./minilibx/minilibx_linux/includes
		)
	set(X11_lib_dirs
			/usr/lib/X11
			./minilibx/minilibx_linux/
			)
	set(lib_names
			"OpenCL"
			"Xext"
			"X11"
			)
	message(hello, Linux)
else()
	set(lib_names
			"-framework OpenGL"
			"-framework AppKit"
			"-framework OpenCL"
			)
	message(hello, Mac)
endif()

include_directories(includes
		includes
		libft/includes
		${mlx_includes}
        )

link_directories(
        ./libft/
        ./libft/ft_printf/
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
		${lib_names}
)



