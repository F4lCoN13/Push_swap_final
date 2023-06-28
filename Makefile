BLACK = \033[0;30m
DARK_GRAY = \033[1;30m
RED = \033[0;31m
LIGHT_RED = \033[1;31m
GREEN = \033[0;32m
LIGHT_GREEN = \033[1;32m
YELLOW = \033[0;33m
LIGHT_YELLOW = \033[1;33m
BLUE = \033[0;34m
LIGHT_BLUE = \033[1;34m
GREEN = \033[0;35m
LIGHT_PURPLE = \033[1;35m
CYAN = \033[0;36m
LIGHT_CYAN = \033[1;36m
LIGHT_GRAY = \033[0;37m
WHITE = \033[1;37m
END = \033[0m

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c					\
		initialization.c 			\
		stack.c						\
		swap.c						\
		push.c						\
		rotate.c					\
		reverse_rotate.c			\
		do_move.c					\
		tiny_sort.c					\
		sort.c						\
		position.c					\
		cost.c 						\
		utils.c						\
		test_error.c				\
		test_error_2.c				\
		ft_split.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n                   $(LIGHT_GREEN)UPDATE  ...$(END)\n"
	@echo "\n                   $(LIGHT_GREEN)UPDATE  ...$(END)\n"
	@echo "\n                   $(LIGHT_GREEN)UPDATE  ...$(END)\n"
	@echo "$(LIGHT_RED)         __      __        .__  $(LIGHT_YELLOW).__              $(LIGHT_GREEN).__          $(LIGHT_BLUE)           ._.$(LIGHT_PURPLE)_._.  $(END)"
	@echo "$(LIGHT_RED)        /  \    /  \ ____  |  | $(LIGHT_YELLOW)|  |     ______  $(LIGHT_GREEN)|  | _____  $(LIGHT_BLUE) ___.__.   | |$(LIGHT_PURPLE) | |   $(END)"
	@echo "$(LIGHT_RED)        \   \/\/   // __ \ |  | $(LIGHT_YELLOW)|  |     \____ \ $(LIGHT_GREEN)|  | \__  \ $(LIGHT_BLUE)<   |  |   | |$(LIGHT_PURPLE) | |   $(END)"
	@echo "$(LIGHT_RED)         \        /\  ___/ |  |_$(LIGHT_YELLOW)|  |__   |  |_> >  $(LIGHT_GREEN) |__/ __ \ $(LIGHT_BLUE) \___ |    \|$(LIGHT_PURPLE)\|\|   $(END)"
	@echo "$(LIGHT_RED)          \__/\  /  \___   >____/$(LIGHT_YELLOW)____/   |   __/ $(LIGHT_GREEN)|____(__   / $(LIGHT_BLUE)/ ____|    __$(LIGHT_PURPLE)____   $(END)"
	@echo "$(LIGHT_RED)               \/       \/       $(LIGHT_YELLOW)        |__|    $(LIGHT_GREEN)         \/ $(LIGHT_BLUE) \/         \/$(LIGHT_PURPLE)\/\/   $(END)"
	@echo "$(LIGHT_GREEN)                                                                                                                    $(END)"
	@echo "$(LIGHT_GREEN)                                                                                                                    $(END)"
	@echo "$(LIGHT_PURPLE)   _____  .__  .__      $(LIGHT_BLUE).__                  $(LIGHT_GREEN)                       $(LIGHT_YELLOW).__.__             .___ $(LIGHT_RED    )._._._. $(END)"
	@echo "$(LIGHT_PURPLE)  /  _  \ |  | |  |     $(LIGHT_BLUE)|__| ______     ___   $(LIGHT_GREEN) ____   _____ ______  $(LIGHT_YELLOW)|__|  |   ____   __| _/ $(LIGHT_RED    )| | | | $(END)"
	@echo "$(LIGHT_PURPLE) /  /_\  \|  | |  |     $(LIGHT_BLUE)|  |/  ___/   _/ ___\ $(LIGHT_GREEN)/  _ \ /     \ __ __\ $(LIGHT_YELLOW)|  |  | _/ __ \ / __ |  $(LIGHT_RED    )| | | | $(END)"
	@echo "$(LIGHT_PURPLE)/    |    \  |_|  |__   $(LIGHT_BLUE)|  |\___ \    \  \__ $(LIGHT_GREEN)(  <_> )  Y Y  \  |_> > $(LIGHT_YELLOW)  |  |_\  ___// /_/ |  $(LIGHT_RED    ) \|\|\| $(END)"
	@echo "$(LIGHT_PURPLE)\__ _|__  /____/____/   $(LIGHT_BLUE)|__/____  >    \___  > $(LIGHT_GREEN)____/|__|_|  /   __/ $(LIGHT_YELLOW)|__|____/\___  >____ |  $(LIGHT_RED    ) ______ $(END)"
	@echo "$(LIGHT_PURPLE)        \/              $(LIGHT_BLUE)        \/         \/ $(LIGHT_GREEN)            \/|__|   $(LIGHT_YELLOW)             \/     \/   $(LIGHT_RED    )\/\/\/  $(END)"

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
