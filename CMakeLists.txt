cmake_minimum_required(VERSION 3.14)
project(fractol C)

add_compile_options(-Wall -Wextra)

if (${CMAKE_BUILD_TYPE} MATCHES "Release")
	add_compile_options(-Werror -O2)
endif()

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
	INCLUDE(FindPkgConfig)
	PKG_SEARCH_MODULE(OPENCL REQUIRED OpenCL)

	set(graphical_includes
        	./minilibx/minilibx_linux/includes/)
	set(graphical_lib_dirs
			/usr/lib/X11
			./minilibx/minilibx_linux/)
	set(graphical_lib_names
			${OPENCL_LIBRARIES}
			"Xext"
			"X11")
else()
	set(graphical_includes
			./minilibx/minilibx_mac/)
	set(graphical_lib_names
			"-framework OpenGL"
			"-framework AppKit"
			"-framework OpenCL")
endif()

include_directories(includes
		includes
		libft/includes
		${graphical_includes}
        )

link_directories(
        ./libft/
        ./libft/ft_printf/
		${graphical_lib_dirs}
)

add_executable(fractol
        ${Sources}
        )

target_link_libraries(fractol
		"m"
        "ftprintf"
		"ft"
        "mlx"
		${graphical_lib_names}
)



