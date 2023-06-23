OS = $(shell uname -s)
NAME = philo
SRC_DIR = src/
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))\
			 $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_UTILES)))
FILES = philo ft_actions ft_session ft_time ft_utils
MYLIB = src/mylib/mylib.a
MYPRINT = src/mylib/ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=address 

all: os $(NAME)

ifeq ($(OS), Darwin)
else
endif

$(NAME): $(OBJS)
	@echo $(GREEN)":::Done:::\n"$(NONE)
	@echo $(CURSIVE)$(GRAY)":::Compiling $(NAME):::" $(NONE)
	@cc $(CFLAGS) $(OBJS) $(MYLIB) $(MYPRINT) -o $(NAME)
	@echo $(GREEN)":::✅ $(NAME) is ready ✅:::"$(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(CURSIVE)$(GRAY)":::Making object files:::" $(NONE)
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -rf $(OBJ_DIR)	
	@make -s clean -C src/mylib/
	@echo $(RED)":::Deleted:::"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting executables:::" $(NONE)
	@rm -f $(NAME) 
	@make -s fclean -C src/mylib/
	@echo $(RED)":::All deleted:::"$(NONE)

re: fclean all

.PHONY:all clean fclean re

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED = '\033[0;31m'
YELLOW = '\033[0;33m'
CURSIVE='\033[3m'

os : 
	@echo $(YELLOW) "                             .          ..            " $(NONE)
	@echo $(YELLOW) "                .uef^"       @88    ..d88"              " $(NONE)
	@echo $(YELLOW) " .d         :d88E           %8P    5888R          u.   " $(NONE)
	@echo $(YELLOW) " @8Ne.   .u  888E            .      888R    ...ue888b  " $(NONE)
	@echo $(YELLOW) " %8888:u@88N   888E .z8k   .@88u    888R    888R Y888r " $(NONE)
	@echo $(YELLOW) "   888I  888.  888E~?888L   888E    888R    888R I888> " $(NONE)
	@echo $(YELLOW) "   888I  888I  888E  888E   888E    888R    888R I888> " $(NONE)
	@echo $(YELLOW) "   888I  888I  888E  888E   888E    888R    888R I888> " $(NONE)
	@echo $(YELLOW) " uW888L  888   888E  888E   888E    888R   u8888cJ888  " $(NONE)
	@echo $(YELLOW) " *88888Nu88P   888E  888E   888&   .888B .  "*888*P"   " $(NONE)
	@echo $(YELLOW) "~  88888F     m888N= 888>   R888"  ^*888%      Y"      " $(NONE)
	@echo $(YELLOW) "   888 ^        Y"   888     ""      "%                " $(NONE)
	@echo $(YELLOW) "   *8E              J88                                " $(NONE)
	@echo $(YELLOW) "    8>              @%                                 " $(NONE)
	@echo $(YELLOW) "    "             :"                                   " $(NONE)
	@echo $(GREEN) "                                            for $(OS)" $(NONE)
