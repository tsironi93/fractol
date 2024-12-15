MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)

NAME=libmlx.dylib

INC=-I.

# Add the flag to suppress warnings
SWIFT_FLAGS= -suppress-warnings

# Compiler flags for C files (suppress messages)
CC_FLAGS=-c -o $@ $< > /dev/null 2>&1

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@swiftc $(INC) $(SWIFT_FLAGS) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz

%.o: %.swift
	@swiftc $(INC) $(SWIFT_FLAGS) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	@swiftc $(INC) $(SWIFT_FLAGS) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

%.o: %.c
	@cc $(CC_FLAGS)

clean:
	rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
