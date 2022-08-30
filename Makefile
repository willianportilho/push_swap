# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/08/31 00:45:09 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		                 \
				ps_init.c         \
				ps_operations.c    \
				ps_sort.c           \
				ps_utils.c           \
				push_swap.c

NAME =			push_swap

CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
RM =			rm -f
RM_ALL =		rm -rf

VAL =			valgrind --leak-check=full --show-leak-kinds=all

LIBFT =			./libft/libft.a

LIB =			./libft
INC =			./inc

SRC_PATH =		src/

OBJ_PATH =		obj/

SRCS =			${addprefix ${SRC_PATH}, ${SOURCES}}

OBJS =			${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}

ITALIC =		\033[3m
BLACK =			\033[30m
RED =			\033[31m
GREEN =			\033[32m
YELLOW =		\033[33m
BLUE =			\033[34m
PURPLE =		\033[35m
CYAN =			\033[36m
WHITE =			\033[37m
RESET =			\033[0m

all:			${NAME}

${NAME}:		${LIBFT} ${OBJS}
				@echo "${CYAN}=========="
				@echo "OBJS OK!!!"
				@echo "==========${RESET}"
				@sleep 1
				@${CC} ${OBJS} ${LIBFT} -o ${NAME}
				@echo "${CYAN}========================"
				@echo "PIPEX PROGRAM CREATED!!!"
				@echo "========================${RESET}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
				@make -C ./libft

ac:				${NAME}
				@make clean
				clear

run:			${NAME}
				clear
				${VAL} ./${NAME} 0 1 2 3 4 5 6 7 9 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 353 36 37 38 39 300 400 40 414 42 43 44 45 46 49 47 48 50 51 52 53 57 54 55 56 58 859 60 61 62 63 64 656 65 66 67 688 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 989 99 100

run2:			${NAME}
				clear
				${VAL} ./${NAME} 0 5 15 13 100 155

rungdb:			${NAME}
				clear
				gdb -q ./${NAME} -tui enable 0 1 2 3 4 5 6 7 9 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 353 36 37 38 39 300 400 40 414 42 43 44 45 46 49 47 48 50 51 52 53 57 54 55 56 58 859 60 61 62 63 64 656 65 66 67 688 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 989 99 100

clean:		
				@${RM_ALL} ${OBJ_PATH}
				@make clean -C ./libft/
				@echo "${CYAN}=================="
				@echo "CLEAN COMPLETED!!!"
				@echo "==================${RESET}"
				@sleep 1

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C ./libft/
				@echo "${CYAN}==================="
				@echo "FCLEAN COMPLETED!!!"
				@echo "===================${RESET}"
				@sleep 1

re:				fclean all
				@echo "${CYAN}==============="
				@echo "RE COMPLETED!!!"
				@echo "===============${RESET}"

norm:
				norminette ${SRCS} ${LIB} ${INC}

.PHONY:			all clean fclean re run norm ac
