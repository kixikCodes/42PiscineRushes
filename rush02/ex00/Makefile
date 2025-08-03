# This rush has been replaced in 42Heilbronn for CORE Game. Despite this,
# here is a working solution to the original rush02 (the newer simplified version!).

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c parsing.c vocab.c ntow.c memory.c
OBJ_DIR = _obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: info $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "Succesfully compiled $(NAME).\n"

info:
	@printf "Compiling $(NAME)...\n"

clean:
	@printf "Cleaned object files.\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "Cleaned executable.\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re info
