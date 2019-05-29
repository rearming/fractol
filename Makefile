# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 23:20:41 by sleonard          #+#    #+#              #
#    Updated: 2019/05/28 14:58:10 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =							\
	fractol

LIBFT =							\
	./libft/libft.a

FT_PRINTF = 				\
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

FILES =							\
		error.c					\
		fractol.c				\
		image.c					\
		init.c					\
		mandelbrot.c			\
		hooks.c					\
		jumps.c					\
		opencl_utils.c			\
		cl_gnl.c				\
		hooks_mandelbrot.c		\
		julia.c					\
		hooks_julia.c			\
		complex_math.c			\

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

COMP = gcc $(COMP_FLAGS) -I $(INCLUDES) -I $(LIBFT_INC) -I $(MLX_INCL)

MLX_FRAMEWORK = -framework OpenGL -framework AppKit

OPEN_CL_FRAMEWORK = -framework OpenCL

FRACTOL_FLAGS = -L $(LIBFT_DIR) -lft -L $(FT_PRINTF) -lftprintf -L $(MLX_LIB) -lmlx $(MLX_FRAMEWORK) $(OPEN_CL_FRAMEWORK)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(COMP) $(FRACTOL_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
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
