# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/09/01 23:29:19 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=                       \
	ft_isalpha.c              \
	ft_isdigit.c                \
	ft_isalnum.c              \
	ft_isascii.c            \
	ft_isprint.c              \
	ft_strlen.c                 \
	ft_memset.c               \
	ft_bzero.c              \
	ft_memcpy.c               \
	ft_memmove.c                \
	ft_strlcpy.c              \
	ft_strlcat.c            \
	ft_toupper.c              \
	ft_tolower.c                \
	ft_strchr.c               \
	ft_strrchr.c            \
	ft_strcmp.c               \
	ft_strncmp.c                \
	ft_memchr.c               \
	ft_memcmp.c             \
	ft_strnstr.c              \
	ft_atoi.c                   \
	ft_atol.c                 \
	ft_calloc.c             \
	ft_strdup.c               \
	ft_substr.c                 \
	ft_strjoin.c              \
	ft_strtrim.c            \
	ft_split.c                \
	ft_itoa.c                   \
	ft_strmapi.c              \
	ft_striteri.c           \
	ft_putchar_fd.c           \
	ft_putstr_fd.c              \
	ft_putendl_fd.c           \
	ft_putnbr_fd.c          \
	get_next_line.c           \
	get_next_line_utils.c       \
	ft_printf.c               \
	ft_print_c.c            \
	ft_print_d_i.c            \
	ft_print_p.c                \
	ft_print_s.c              \
	ft_print_u.c            \
	ft_print_x_lower.c        \
	ft_print_x_upper.c          \
	ft_pre_c.c                \
	ft_pre_d_i.c            \
	ft_pre_p.c                \
	ft_pre_s.c                  \
	ft_pre_u.c                \
	ft_pre_x_lower.c        \
	ft_pre_x_upper.c          \
	ft_lstnew.c                 \
	ft_lstadd_front.c         \
	ft_lstsize.c            \
	ft_lstlast.c              \
	ft_lstadd_back.c            \
	ft_lstdelone.c            \
	ft_lstdelone_alt.c      \
	ft_lstclear.c             \
	ft_lstclear_alt.c           \
	ft_lstiter.c              \
	ft_lstmap.c             \
	ft_lstnew_n.c             \
	ft_lstadd_front_n.c         \
	ft_lstsize_n.c            \
	ft_lstlast_n.c          \
	ft_lstadd_back_n.c        \
	ft_lstdelone_n.c            \
	ft_lstclear_n.c           \
	ft_lstcpy_n.c           \
	ft_lstncpy_n.c

OBJ			= ${SRC:.c=.o}

NAME		= libft.a

CC			= cc

CFLAGS		= -g3 -Wall -Wextra -Werror

CREATE		= ar rc

RM			= rm -f

ITALIC =	\033[3m
BLACK =		\033[30m
RED =		\033[31m
GREEN =		\033[32m
YELLOW =	\033[33m
BLUE =		\033[34m
PURPLE =	\033[35m
CYAN =		\033[36m
WHITE =		\033[37m
RESET =		\033[0m

${NAME}:	${OBJ}
			@${CREATE} ${NAME} ${OBJ}
			@echo "${CYAN}================="
			@echo "LIBFT COMPILED!!!"
			@echo "=================${RESET}"
			@sleep 2

.c.o:		
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

clean:
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re