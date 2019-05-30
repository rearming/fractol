# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 23:20:41 by sleonard          #+#    #+#              #
#    Updated: 2019/05/30 18:16:41 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# HOOKS
# ============================================================================ #

HOOKS_FILES =					\
		hooks.c					\
		hooks_mandelbrot.c		\
		hooks_julia.c			\

HOOKS_DIR =						\
	./sources/hooks/

HOOKS_OBJ = $(addprefix $(OBJ_DIR), $(HOOKS_FILES:.c=.o))

# ============================================================================ #
# OPEN_CL
# ============================================================================ #

OPEN_CL_FILES =					\
		opencl_utils.c			\
		cl_gnl.c				\
		cl_render.c				\

OPEN_CL_DIR =					\
	./sources/open_cl/

OPEN_CL_OBJ = $(addprefix $(OBJ_DIR), $(OPEN_CL_FILES:.c=.o))

# ============================================================================ #
# TERMINAL
# ============================================================================ #

TERMINAL_FILES =				\
		terminal.c				\
		parse_term_input.c		\
		term_string_utils.c		\

TERMINAL_DIR =					\
	./sources/terminal/

TERMINAL_OBJ = $(addprefix $(OBJ_DIR), $(TERMINAL_FILES:.c=.o))

# ============================================================================ #
# UTILS
# ============================================================================ #

UTILS_FILES =					\
		error.c					\
		image.c					\
		init.c					\
		complex_math.c			\
		bresenham.c				\

UTILS_DIR =						\
	./sources/utils/

UTILS_OBJ = $(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))

# ============================================================================ #
# MAIN
# ============================================================================ #

MAIN_FILES =					\
		fractol.c				\
		julia.c					\
		mandelbrot.c			\
		jumps.c					\

MAIN_DIR =						\
	./sources/

MAIN_OBJ = $(addprefix $(OBJ_DIR), $(MAIN_FILES:.c=.o))

# ============================================================================ #
# BUILD FRACTOL
# ============================================================================ #

NAME =							\
	fractol

OBJ =							\
	$(MAIN_OBJ)					\
	$(UTILS_OBJ)				\
	$(TERMINAL_OBJ)				\
	$(OPEN_CL_OBJ)				\
	$(HOOKS_OBJ)				\

LIBFT =							\
	./libft/libft.a

FT_PRINTF = 					\
	./libft/ft_printf/

MLX_LIB = 						\
	/usr/local/lib/

OBJ_DIR =						\
	./temp/

SRC_DIR =						\
	./sources/

COMP_FLAGS = 					\
	-Wall -Wextra -Werror -O2

INCLUDES = 						\
	./includes/

MLX_INCL =						\
	/usr/local/include/

COMP = gcc $(COMP_FLAGS) -I $(INCLUDES) -I $(LIBFT_INC) -I $(MLX_INCL)

MLX_FRAMEWORK = -framework OpenGL -framework AppKit

OPEN_CL_FRAMEWORK = -framework OpenCL

FRACTOL_FLAGS = -L $(LIBFT_DIR) -lft -L $(FT_PRINTF) -lftprintf -L $(MLX_LIB) -lmlx $(MLX_FRAMEWORK) $(OPEN_CL_FRAMEWORK)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(COMP) $(FRACTOL_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(MAIN_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(OPEN_CL_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(TERMINAL_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(UTILS_DIR)%.c
	$(COMP) -c $< -o $@

$(OBJ_DIR)%.o : $(HOOKS_DIR)%.c
	$(COMP) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re : fclean $(NAME)

# ============================================================================ #
# 						LIBFT
# ============================================================================ #

LIBFT_DIR =				\
	./libft/			\

LIBFT_INC = 			\
	./libft/includes/	\

$(LIBFT) :
	@make -C $(LIBFT_DIR)
	@make printf -C $(LIBFT_DIR)
