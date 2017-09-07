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

NAME = visualizer
HEAD = header/visualizer.h

FILES_PATH	= ./files
OBJECTS_PATH = ./objects

SRC =	main print_func filling_struct nulling

FLAGS = -Wall -Wextra -Werror
C_FILES = $(addprefix $(FILES_PATH)/, $(addsuffix .c, $(SRC)))
OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $@ $^ ../libft/libft.a ../ft_printf/ft_printf.a
	@echo $(CYAN) "\n\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ ../libft/libft.a ../ft_printf/ft_printf.a
	@echo $(GREEN) "\tvisualizer\t- has been made\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@echo $(YELLOW) "\t\t\t\tVisualizer"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned.\n"$(RESET)

fclean:
	@echo $(YELLOW)"\t\t\t\tVisualizer"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED)"\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tvisualizer have been cleaned.\n"$(RESET)

re: fclean all