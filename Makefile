CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES := \
    ft_printf.c \
    ft_parse_format.c \
    ft_print_char.c 

OFILES := $(CFILES:.c=.o)

NAME := libftprintf.a

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ft_printf.h


all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	ar rcs $@ $(OFILES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp ./$(LIBFT) ./$(NAME)

$(OFILES): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
