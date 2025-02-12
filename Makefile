NAME	=	fractol
BONUS_NAME = fractol_bonus

SRC		= 	main.c fractol_utils.c math.c str_utils.c
BONUS_SRC = main_bonus.c fractol_utils_bonus.c math_bonus.c str_utils_bonus.c

SDIR 	= 	$(addprefix src/, $(SRC))
BDIR 	= 	$(addprefix src/, $(BONUS_SRC))

SOBJ	= 	$(SDIR:.c=.o)
BOBJ	= 	$(BDIR:.c=.o)

HEADER	=	fractol.h

CC		= 	cc

FLAGS	= 	-Wall -Wextra -Werror -g3 -O2

ifdef DEBUG
FLAGS	+=	-fsanitize=address -fno-omit-frame-pointer
endif

# for Mac compilation
LIB		= 	-framework OpenGL -framework AppKit

MLX		= 	-L$(MLXDIR) -lmlx

DYLIB	=	libmlx.dylib

MLXDIR	=	mlx

# COLORS
BLUE	= 	\033[38;5;27m
CYAN	= 	\033[38;5;51m
PINK	=	 \033[38;5;211m
GREEN	= 	\033[38;5;72m
TURQ	= 	\033[38;5;37m
WHITE	= 	\033[38;5;15m
YELLOW	= 	\033[38;5;220m
C		=	\033[38;5;
O		=	37
L		=	m
SHIFT	=	$(eval O=$(shell echo $$((($(O)%13)+1))))

LBOR	=	"▌│█║▌║▌║ "
RBOR	= 	" ║▌║▌║█│▌"

all: $(NAME)

$(NAME): $(SOBJ) $(MLX)
	@$(MAKE) fractol_ascii
	@$(CC) $(FLAGS) $(SOBJ) $(MLX) $(LIB) -o $(NAME)
	@echo "\n\t   $(TURQ)$(LBOR)Fractol compiled$(RBOR)$(WHITE)\n"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ) $(MLX)
	@$(MAKE) fractol_ascii
	@$(CC) $(FLAGS) $(BOBJ) $(MLX) $(LIB) -o $(BONUS_NAME)
	@echo "\n\t   $(YELLOW)$(LBOR)Fractol Bonus compiled$(RBOR)$(WHITE)\n"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(MLX):
	@make -C $(MLXDIR)
	@cp -rf $(MLXDIR)/$(DYLIB) .
	@echo "\n\t   $(TURQ)$(LBOR)minilibx compiled$(RBOR)$(WHITE)\n"

debug: $(SOBJ)
	@echo "\n\t   $(GREEN)$(LBOR)Debug mode$(RBOR)$(WHITE)\n"
	@$(MAKE) DEBUG=1

clean:
	@echo "\n\t   $(PINK)$(LBOR)Cleaning$(RBOR)$(WHITE)\n"
	@rm -rf $(SOBJ) $(BOBJ)
	@make -C $(MLXDIR) clean

fclean: clean
	@echo "\n\t   $(CYAN)$(LBOR)Clean af$(RBOR)$(WHITE)\n"
	@rm -rf $(NAME) $(BONUS_NAME)
	@rm -rf libmlx.dylib
	@rm -rf screenshot.bmp

re:
	@echo "\n\t   $(BLUE)$(LBOR)Aww here we go again$(RBOR)$(WHITE)\n"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re bonus

fractol_ascii:
	@echo "$(C)$(O)$(L)░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░      ░▒▓█▓▒░ ";
	@echo "$(C)$(O)$(L)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░ ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░ ";
	@echo "$(C)$(O)$(L)░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░ ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░ ";
	@echo "$(C)$(O)$(L)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░              ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░   ░▒▓██████▓▒░░▒▓████████▓▒░▒▓█▓▒░ ";