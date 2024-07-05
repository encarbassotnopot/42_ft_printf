SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = ft_printf.h libft/libft.h

BUILD_DIR = build
INCLUDE_DIR = include

NAME = libprintf.a
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I. -Ilibft -fsanitize=address

ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $?

$(BUILD_DIR)/printtest.o: printtest.c $(HDR_FILES) Makefile | $(BUILD_DIR)
	$(CC) -c $< -o $@ -I. -Ilibft

$(BUILD_DIR)/%.o: %.c $(HDR_FILES) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(BUILD_DIR):
	mkdir -p $@

clean reclean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all reclean

rebonus: fclean bonus reclean

info:
	$(info $(SRC_FILES))
	$(info $(SRC_BONUS))


.PHONY: all fclean reclean re bonus rebonus info
