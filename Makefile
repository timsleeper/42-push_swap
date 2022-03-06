# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 14:44:19 by ftadeu-d          #+#    #+#              #
#    Updated: 2022/03/06 15:37:53 by ftadeu-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/main.c \
		src/fill_indices.c \
		src/libft_utils.c \
		src/list_operations.c \
		src/mov_push.c \
		src/mov_revrotate.c \
		src/mov_rotate.c \
		src/mov_swap.c \
		src/normal_sort.c \
		src/small_sort.c \
		src/validate_args.c \
		src/misc_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}
${NAME}: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ${NAME}

clean:
	$(RM) ${NAME} $(OBJS)

fclean: clean
	$(RM) -f ${NAME} $(OBJS)

re: fclean all

.PHONY: all clean fclean re
