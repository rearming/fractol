NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2 -fPIC

LIBFT_INCL = ./libft/includes

PRINTF_INCL = ./includes

DIR_S = ./srcs

DIR_O = temp

SOURCES =						\
		ft_printf_family.c		\
		error.c					\
		format_filler.c			\
		format_parser.c			\
		int.c					\
		split_flags.c			\
		string.c				\
		int.c					\
		floats.c				\
		fields_check.c			\
		format_filler_utils.c	\
		main_processing.c		\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

.PHONY: update
update:
	git submodule update

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	clang $(FLAGS) -I $(PRINTF_INCL) -I $(LIBFT_INCL) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
