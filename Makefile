NAME	=	fractol

SRC		= 	main.c fractol_utils.c math.c

SDIR 	= 	$(addprefix src/, $(SRC))

SOBJ	= 	$(SDIR:.c=.o)

ifdef WITH_BONUS
OBJ 	= 	$(SOBJ)
else
OBJ 	= 	$(SOBJ)
endif

HEADER	=	fractol.h

CC		= 	cc

FLAGS	= 	-Wall -Wextra -Werror -g3

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

$(NAME): $(OBJ) $(MLX)
	@$(MAKE) fractol_ascii
	@$(CC) $(FLAGS) $(OBJ) $(MLX) $(LIB) -o $(NAME)
	@echo "\n\t   $(TURQ)$(LBOR)Fractol compiled$(RBOR)$(WHITE)\n"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(MLX):
	@make -C $(MLXDIR)
	@cp -rf $(MLXDIR)/$(DYLIB) .
	@echo "\n\t   $(TURQ)$(LBOR)minilibx compiled$(RBOR)$(WHITE)\n"

debug: $(OBJ)
	@echo "\n\t   $(GREEN)$(LBOR)Debug mode$(RBOR)$(WHITE)\n"
	@$(MAKE) DEBUG=1

bonus: $(OBJ)
	@echo "\n\t   $(YELLOW)$(LBOR)Bonus mode$(RBOR)$(WHITE)\n"
	@$(MAKE) WITH_BONUS=1 all

clean:
	@echo "\n\t   $(PINK)$(LBOR)Cleaning$(RBOR)$(WHITE)\n"
	@rm -rf $(OBJ)
	@make -C $(MLXDIR) clean

fclean: clean
	@echo "\n\t   $(CYAN)$(LBOR)Clean af$(RBOR)$(WHITE)\n"
	@rm -rf $(NAME)
	@rm -rf libmlx.dylib
	@rm -rf screenshot.bmp

re:
	@echo "\n\t   $(BLUE)$(LBOR)Aww here we go again$(RBOR)$(WHITE)\n"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

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