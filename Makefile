NAME = fractol
SRC = main.c
#utils.c draw.c map_parser.c path_checker.c game_utils.c map_parser_utils.c free.c)
#GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
#PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)

OBJ := $(SRC:%.c=%.o)
#GNL_OBJ := $(GNL_SRC:%.c=%.o)
#PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

mlx_check:
	@if [ ! -d "$(mlx)" ]; then \
		echo "Error: $(mlx) directory is missing."; \
		exit 1; \
	fi
	@if [ ! -f "$(MLX_LIB)" ]; then \
		echo "Error: $(MLX_LIB) library is missing. Please build it in the $(mlx) directory."; \
		exit 1; \
	fi

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	cc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re : fclean all

#.PHONY: all clean fclean re

# make -j !fast make! 