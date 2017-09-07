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

NAME = filler
HEAD = header/filler.h

FILES_PATH = ./files
OBJECTS_PATH = ./objects

SRC =	main get_info nulling pasting new_struct map\
		tactic print manhattan_distance

FLAGS = -Wall -Wextra -Werror
C_FILES = $(addprefix $(FILES_PATH)/, $(addsuffix .c, $(SRC)))
OBJ = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C libft/
	@make -C ft_printf/
	@make -C visualizer/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ libft/libft.a ft_printf/ft_printf.a
	@echo $(GREEN) "\tfiller\t\t- has been made\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

cleanlib:
	@make clean -C ./ft_printf
	@make clean -C ./libft
	@make clean -C ./visualizer

fcleanlib:
	@make fclean -C ./ft_printf
	@make fclean -C ./libft
	@make fclean -C ./visualizer

clean: cleanlib
	@echo $(YELLOW) "\t\t\t\tFiller"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned.\n"$(RESET)

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tFiller"$(RESET)
	@rm -f $(OBJ)
	@echo $(RED)"\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tfiller have been cleaned.\n"$(RESET)

re: fclean all