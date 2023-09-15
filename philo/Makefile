CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

NAME_PROJECT		= philosophers

HEADER_PATH		= ./include

SRC_CLIENT_PATH	= ./src/philosophers.c ./src/helpers.c

BINARY_OUT_PROJ	= philosophers

all: $(BINARY_OUT_PROJ)

$(BINARY_OUT_PROJ): $(SRC_CLIENT_PATH)
	@ $(CC) $(CFLAGS) $(SRC_CLIENT_PATH) -o $(NAME_PROJECT) -I$(HEADER_PATH)

clean:
	@ $(MAKE) clean -C .

fclean: clean
	@ $(MAKE) fclean -C .
	@ rm -f $(BINARY_OUT_PROJ)

re: fclean all

.PHONY: all clean fclean re
