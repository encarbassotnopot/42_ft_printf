SRC_FILES = formatters.c ft_printf.c parser.c prints.c set_flag.c
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = ft_printf.h ft_printf_utils.h

BUILD_DIR = build

NAME = libftprintf.so

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I. -I../libft -fPIC

ARFLAGS = rcs

all: $(NAME) 

$(NAME): $(OBJ_FILES)
	$(CC) -shared -o $@ $^
	#$(AR) $(ARFLAGS) $@ $?

$(BUILD_DIR)/%.o: %.c Makefile $(HDR_FILES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean reclean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

.PHONY: all fclean reclean re 
