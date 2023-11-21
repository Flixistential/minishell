NAME = Minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

EXECUTION = ./src/execution/execution.c

SRC =	./src/main.c\
		./src/execution.c\
		./src/builtin.c\
		.src/init.c\
		.src/unset.c\
		./src/export.c
		
	
OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))
LIBFT = libft.a
LDIR = libft/
REMOVE = rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;30m
NC = \033[0m

INCDIR = include

#--- READLINE ---#
HISTORYLIB    =    readline/libhistory.a
READLINELIB    =    readline/libreadline.a
ANBOISVE = $(shell test -e include/readline/libreadline.a ; echo "$$?")

${NAME}:$(OBJ_DIR) ${OBJS} ${LDIR}${LIBFT}
		@$(CC) $(CFLAGS) $(OBJS) ${LDIR}${LIBFT} -L$(INCDIR)/readline/ -lreadline -lncurses -o $(NAME)
		@printf "\r${GREEN}Compilation complete.\n"


all: rl ${NAME}

$(OBJ_DIR)/%.o: src/%.c
	@printf "${GREEN}Compiling: ${YELLOW}$(CC) $(CFLAGS) -c $< -o $@"

	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[K"  # Clear the line

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

${LDIR}${LIBFT}:
	${MAKE} -C ${LDIR}

rl:
	@if test $(ANBOISVE) = 1 ; then \
		cd include/readline && ./configure && make ; \
	else \
		echo "$(GREEN)readline all ready make.$(RESET)" ; sleep 1; \
	fi

readline:
	@cd include/readline && ./configure && $(MAKE)
	@$(MAKE)

readline_remove: fclean
	@cd include/readline && $(MAKE) distclean

clean :
		@${REMOVE} ${OBJS}
		@${MAKE} -C ${LDIR} clean
		@echo "${RED}Object files removed."
	
fclean :clean
		@${REMOVE} ${NAME}
		@${MAKE} -C ${LDIR} fclean
		@echo "${RED}Executable removed."

re:fclean all
 
.PHONY: all clean fclean re

