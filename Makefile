# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/08/26 02:44:14 by wportilh         ###   ########.fr        #
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
				${VAL} ./${NAME} -104 -505 -400 211 322

run2:			${NAME}
				clear
				./${NAME} 1 2 3 4 5 6

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
