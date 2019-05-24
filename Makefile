# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 23:20:41 by sleonard          #+#    #+#              #
#    Updated: 2019/05/24 16:17:56 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =							\
	fractol

LIBFT =							\
	./libft/

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
	error.c						\
	fractol.c					\
	image.c						\
	init.c						\
	mandelbot.c					\

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

COMP = gcc $(COMP_FLAGS) -I $(INCLUDES) -I $(LIBFT_INC) -I $(MLX_INCL)

FRACTOL_FLAGS = -L $(LIBFT) -lft -L $(MLX_LIB) -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(COMP) $(FRACTOL_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(COMP) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re : fclean $(NAME)

# ============================================================================ #
# 						LIBFT
# ============================================================================ #

LIBFT_DIR =				\
	./libft/			\

LIBFT_INC = 			\
	./libft/includes/	\

$(LIBFT) :
	@make -C $(LIBFT)
