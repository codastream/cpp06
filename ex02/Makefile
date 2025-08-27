NAME		:=	ex02

#==============================COMPIL===========================#

CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

MAKEFLAGS	:=	--no-print-directory

#================================COUNT============================#

NB_COMP	:=	1

ifndef RECURSION
TO_COMP :=	$(shell make RECURSION=1 -n | grep Compiling | wc -l)
else
TO_COMP	:=	1
endif

PERCENT	:= 0

#==============================COLORS==============================#
NOC			= \e[0m
BOLD		= \e[1m
DIM			= \e[2m
UNDERLINE	= \e[4m

BLACK		= \e[1;30m
RED			= \e[1;31m
GREEN		= \e[1;32m
YELLOW		= \e[1;33m
BLUE		= \e[1;34m
PURPLE		= \e[1;35m
CYAN		= \e[1;36m
WHITE		= \e[1;37m

BLACK_BG 	= \e[0;40m
RED_BG 		= \e[0;41m
GREEN_BG 	= \e[0;42m
YELLOW_BG 	= \e[0;43m
BLUE_BG 	= \e[0;44m
MAGENTA_BG 	= \e[0;45m
CYAN_BG 	= \e[0;46m
WHITE_BG 	= \e[0;47m

#================================DIRS============================#

SRC_DIR			:=	srcs
INCLUDES_DIR	:=	includes
BUILD_DIR		:=	.build

#==============================SOURCES===========================#

# no duplicates

SRCS_FILES:=	main.cpp\
				utils.cpp\
				Base.cpp\
				A.cpp\
				B.cpp\
				C.cpp\

SRCS:=			$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

#=============================OBJECTS===========================#

OBJS:=			${SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o}

#=============================INCLUDES===========================#

INC				:=	-I $(INCLUDES_DIR)

#================================DIR=============================#

DIRS			:=	$(sort $(shell dirname $(OBJS)))

#===============================RULES============================#

all: $(NAME)

$(DIRS):
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "\n$(GREEN)Create binaries$(NOC)"
	@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $@

# $$@D gets directory from current target - pipe prevents from relink
# tput cols to get columns nb of terminal
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DIRS)
	@mkdir -p $(BUILD_DIR)
	@if [ $(NB_COMP) -eq 1 ]; then echo "$(BOLD)Compilation of source files :$(NOC)";fi
	$(eval PERCENT=$(shell expr $(NB_COMP)00 "/" $(TO_COMP)))
	@if [ $(PERCENT) -le 30 ]; then echo -n "$(RED)"; elif [ $(PERCENT) -le 66 ]; then echo -n "$(YELLOW)"; elif [ $(PERCENT) -gt 66 ]; then echo -n "$(GREEN)"; fi
	@echo -n "\r"; for i in $$(seq 1 $$(/usr/bin/tput cols)); do echo -n " "; done
	@echo -n "\r"; for i in $$(seq 1 25); do if [ $$(expr $$i "*" 4) -le $(PERCENT) ]; then echo -n "█"; else echo -n " "; fi; done; echo -n "";
	@printf " $(NB_COMP)/$(TO_COMP) - Compiling $<"
	@echo -n "$(NOC)"
	@$(CC) $(CFLAGS) $(INC) $< -c -o $@
	$(eval NB_COMP=$(shell expr $(NB_COMP) + 1))

clean:
	@echo "$(RED)Remove objects$(NOC)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)Remove binary$(NOC)"
	@rm -f $(NAME)

re: fclean
	@make

.PHONY: all clean fclean re $(DIRS)
