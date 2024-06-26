CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES := \
    ft_printf.c \
    ft_parse_format.c \
    ft_print_char.c \
	ft_print_string.c \
	ft_print_decnum.c \
	ft_print_num_nopre.c \
	ft_print_pointer.c \
	ft_print_unsigned.c \
	ft_print_hex.c \
	ft_print_percent.c \
	ft_utils.c \
	ft_putnbr_base.c \
	ft_put_utils.c \

OBJDIR := obj
OFILES := $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME := libftprintf.a

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ft_printf.h

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJDIR) $(OFILES)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $(OFILES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
