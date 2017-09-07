# ----- Colors -----
BLACK ="\033[1;30m"
RED ="\033[1;31m"
GREEN ="\033[1;32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN ="\033[1;35m"
PURPLE ="\033[1;36m"
WHITE ="\033[1;37m"
EOC ="\033[0;0m"
RESET = "\x1b[0m"
# ==================

NAME = ft_printf.a
HEAD = header/ft_printf.h

SRC =	src/ft_check_flags.c src/ft_for_decimal.c src/ft_for_lists.c src/ft_for_octals.c\
		src/ft_for_string.c src/ft_lst_modify.c src/ft_printf.c src/libft.c\
		print/ft_b.c print/ft_c_big.c print/ft_c.c print/ft_d.c\
		print/ft_o.c print/ft_p.c print/ft_percent.c print/ft_print_flags.c print/ft_s_big.c\
		print/ft_s.c print/ft_u.c print/ft_x.c print/ft_xb.c

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) ../libft/libft.a
	@ranlib $(NAME)
	@echo $(CYAN) "\n\tCompiling $@"$(RESET)
	@echo $(GREEN) "\tft_printf.a\t- has been made\n"$(RESET)
%.o: %.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@gcc $(FLAGS) -c -o $@ $< 

clean:
	@echo $(YELLOW) "\t\t\t\tFT_PRINTF"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED) "\t.o files have been cleaned.\n"$(RESET)

fclean:
	@echo $(YELLOW) "\t\t\t\tFT_PRINTF"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tft_printf.a have been cleaned.\n"$(RESET)

re: fclean all