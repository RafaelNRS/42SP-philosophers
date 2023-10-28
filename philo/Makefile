NAME			= philosophers

HEADER_DIR		= ./include/
HEADER			= philosophers.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

SRC_DIR			= ./src/
SRC				= 	philosophers.c \
					helpers.c \
					validation_helpers.c \
					validation_helpers_two.c \
					free_helpers.c \
					threads.c \
					threads_two.c \
					monitor.c 
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR			= ./objs/
OBJ				= 	philosophers.o \
					helpers.o \
					validation_helpers.o \
					validation_helpers_two.o \
					free_helpers.o \
					threads.o \
					threads_two.o \
					monitor.o
OBJ_PATH		= $(addprefix $(OBJ_DIR), $(OBJ))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -pthread -g3

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH) $(HEADER_PATH)
	@ $(CC) $(CFLAGS) -c $(SRC_PATH) -I $(HEADER_DIR)
	@ mkdir -p $(OBJ_DIR)
	@ mv $(OBJ) $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
	@ mkdir -p $(BIN)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "object files erased successfully!"

fclean: clean
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "$(NAME) binaries erased successfully!"

re: fclean all

leaks:
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) -g $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) with leak check option compiled successfully!"

simple:
	@ mkdir -p $(BIN)
	@ $(CC) -g $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) without compile flags compiled successfully!"

.PHONY: all clean fclean re
