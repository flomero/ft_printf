CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES := \
	ft_printf.c

OFILES := $(CFILES:.c=.o)

NAME := libftprintf.a

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	ar rcs $@ $^

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OFILES): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
