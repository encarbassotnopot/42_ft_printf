SRC_FILES = formatters.c ft_printf.c parser.c prints.c set_flag.c
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = ft_printf.h

BUILD_DIR = build

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I. -Ilibft

ARFLAGS = rcs

all: $(LIBFT) $(NAME) 

bonus: $(LIBFT) $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $?

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft
	cp $(LIBFT) $(NAME)

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
