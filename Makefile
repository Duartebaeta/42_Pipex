NAME := pipex
CC := gcc
CFLAGS := -Wall -Wextra -Werror

PATH_SRC := ./src
PATH_LIBFT := ./libft
PATH_BUILD := ./build
PATH_OBJ := $(PATH_BUILD)/obj
PATH_INCLUDES := ./includes

BIN := ./$(NAME)

SRC := $(PATH_SRC)/test.c \
		$(PATH_SRC)/pipex.c

OBJ := $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJ), $(SRC)))

LIBFT := $(PATH_LIBFT)/libft.a

all:$(BIN)

$(BIN): $(OBJ) | $(LIBFT)
		@$(CC) $(CFLAGS) -o $(@) $^ -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDES)
		@echo "\033[33m[Compiling]\033[0m"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@echo "\033[33m[CREATING ${@F}]\033[0m"
		@$(CC) $(CFLAGS) -c $(^) -o $@

$(LIBFT):
		@make -C $(PATH_LIBFT)

$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJ)

clean:
		@echo "\033[38;5;1m[REMOVING OBJECTS]\033[0m"
		@rm -rf $(PATH_OBJ)

fclean: clean
		@echo "\033[38;5;1m[REMOVING BINARIES]\033[0m"
		@rm -rf $(PATH_BUILD) $(NAME)
		@make fclean -C $(PATH_LIBFT)

exe: all
		@./$(NAME)

re: fclean all

.PHONY: all exe
