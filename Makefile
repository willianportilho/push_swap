# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/09/07 23:42:30 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		                 \
				ps_init.c         \
				ps_operations.c    \
				ps_sort.c           \
				ps_sort_2.c          \
				ps_utils.c            \
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
				@echo "003 numbers"
				@echo -n "${GREEN}Checker result : "; ARG=$$(seq -1 1 | shuf); ./push_swap $$ARG | ./checker_linux $$ARG
				@echo -n "Operations     : "; ARG=$$(seq -1 1 | shuf); ./push_swap $$ARG | wc -w; echo "${RESET}"
				@echo "005 numbers"
				@echo -n "${YELLOW}Checker result : "; ARG=$$(seq -2 2 | shuf); ./push_swap $$ARG | ./checker_linux $$ARG
				@echo -n "Operations     : "; ARG=$$(seq -2 2 | shuf); ./push_swap $$ARG | wc -w; echo "${RESET}"
				@echo "100 numbers: "
				@echo -n "${GREEN}Checker result : "; ARG=$$(seq -50 49 | shuf); ./push_swap $$ARG | ./checker_linux $$ARG
				@echo -n "Operations     : "; ARG=$$(seq -50 49 | shuf); ./push_swap $$ARG | wc -w; echo "${RESET}"
				@echo "500 numbers: "
				@echo -n "${YELLOW}Checker result : "; ARG=$$(seq -250 249 | shuf); ./push_swap $$ARG | ./checker_linux $$ARG
				@echo -n "Operations     : "; ARG=$$(seq -250 249 | shuf); ./push_swap $$ARG | wc -w; echo "${RESET}"

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
