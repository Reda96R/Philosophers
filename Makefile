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
	@echo $(YELLOW) " .S_sSSs     .S    S.    .S  S.        sSSs_sSSs    " $(NONE)
	@echo $(YELLOW) ".SS~YS%%b   .SS    SS.  .SS  SS.      d%%SP~YS%%b  " $(NONE)
	@echo $(YELLOW) "S%S    S%b  S%S    S%S  S%S  S%S     d%S'      S%b  " $(NONE)
	@echo $(YELLOW) "S%S    S%S  S%S    S%S  S%S  S%S     S%S       S%S " $(NONE)
	@echo $(YELLOW) "S%S    d*S  S%S SSSS%S  S&S  S&S     S&S       S&S  " $(NONE)
	@echo $(YELLOW) "S&S   .S*S  S&S  SSS&S  S&S  S&S     S&S       S&S  " $(NONE)
	@echo $(YELLOW) "S&S_sdSSS   S&S    S&S  S&S  S&S     S&S       S&S " $(NONE)
	@echo $(YELLOW) "S&S~YSSY    S&S    S&S  S&S  S&S     S&S       S&S " $(NONE)
	@echo $(YELLOW) "S*S         S*S    S*S  S*S  S*b     S*b       d*S  " $(NONE)
	@echo $(YELLOW) "S*S         S*S    S*S  S*S  S*S.    S*S.     .S*S " $(NONE)
	@echo $(YELLOW) "S*S         S*S    S*S  S*S   SSSbs   SSSbs_sdSSS  " $(NONE)
	@echo $(YELLOW) "S*S         SSS    S*S  S*S    YSSP    YSSP~YSSY   " $(NONE)
	@echo $(YELLOW) "SP                 SP   SP                         " $(NONE)
	@echo $(YELLOW) "Y                  Y    Y                          " $(NONE)
	@echo $(GREEN) "                                            for $(OS)" $(NONE)
