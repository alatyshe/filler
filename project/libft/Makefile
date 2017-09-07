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

NAME = libft.a
HEAD = header/libft.h

FILES_PATH = ./files
OBJECTS_PATH = ./objects

SRC =	ft_atoi ft_lstmap ft_putstr ft_strmapi ft_lstmap ft_putstr_fd\
		ft_strncat ft_lstnew ft_strcat ft_strncmp ft_bzero ft_memalloc\
		ft_strchr ft_strncpy ft_isalnum ft_memccpy ft_strclr ft_strndup\
		ft_isalpha ft_memchr ft_strcmp ft_strnequ ft_isascii ft_memcmp\
		ft_strcpy ft_strnew ft_isblank ft_memcpy ft_strdel ft_strnstr\
		ft_isdigit ft_memdel ft_strdup ft_strrchr ft_isnumber ft_memmove\
		ft_strequ ft_strsplit ft_isprint ft_memset ft_striter ft_strstr\
		ft_isupper ft_putchar ft_striteri ft_strsub ft_itoa ft_putchar_fd\
		ft_strjoin ft_strtrim ft_lstadd ft_putendl ft_strlcat ft_tolower\
		ft_lstdel ft_putendl_fd ft_lst_size ft_toupper ft_lstdelone\
		ft_putnbr ft_strlen ft_lstiter ft_putnbr_fd ft_strmap\
		get_next_line isdigit_str isalpha_str


FLAGS = -Wall -Wextra -Werror
C_FILES = $(addprefix $(FILES_PATH)/, $(addsuffix .c, $(SRC)))
OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) "\n\tCompiling $@"$(RESET)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) "\tlibft.a\t\t- has been made\n"$(RESET)
$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<\tinto\t$@"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@echo $(YELLOW) "\t\t\t\tLIBFT"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned.\n"$(RESET)

fclean:
	@echo $(YELLOW) "\t\t\t\tLIBFT"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tlibft.a have been cleaned.\n"$(RESET)

re: fclean all
