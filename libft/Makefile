# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 15:55:08 by akhossan          #+#    #+#              #
#    Updated: 2019/12/03 22:20:53 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CFLAGS		=	-Werror -Wall -Wextra

SRC			=	$(shell find . -type f -name  "*.c")

OBJS		=	$(SRC:.c=.o)

HEADER	 	=	libft.h get_next_line.h

%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) -I. $< -o $@

all:$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
