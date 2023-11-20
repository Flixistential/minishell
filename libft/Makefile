NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
src =		ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strchr.c\
			ft_strncmp.c\
			ft_strdup.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_split.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_printf.c\
			ft_print_int.c\
			ft_print_adress.c\
			ft_print_u.c\
			ft_print_hex.c\
			get_next_line.c\
			ft_isspace.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_2darray_strlen.c\
			ft_free_2darray.c
OBJS 	= ${src:.c=.o}
LIBC 	= ar rcs
REMOVE	= rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;30m
NC = \033[0m
 
${NAME}: ${OBJS}
		 @${LIBC} ${NAME} ${OBJS}
 
all:$(NAME)

%.o: %.c
	@printf "${GREEN}Compiling: $(CC) $(CFLAGS) -c $< -o $@"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r\033[K"

clean :
		@${REMOVE} ${OBJS} ${BONUS_OBJS}
		@printf "\r\033[K"
 
fclean :clean
		@${REMOVE} $(NAME)
		@printf "\r\033[K"
 
re:fclean all
 
.PHONY: all clean fclean re 