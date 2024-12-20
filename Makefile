# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 21:56:47 by mmilicev          #+#    #+#              #
#    Updated: 2024/12/01 21:02:30 by mmilicev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
OP = operations/
OP_DIR = $(OP)swap.c $(OP)push.c $(OP)rotate.c $(OP)rev_rotate.c $(OP)sort_3.c $(OP)sort_stacks.c
SRCS = $(OP_DIR) push_swap.c utils_stack.c set_stack.c errors_handling.c set_stack_a.c set_stack_b.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

all: ${NAME} 
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re