# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 16:56:35 by akhossan          #+#    #+#              #
#    Updated: 2019/12/03 22:35:49 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	checker

NAME2	=	push_swap

SRC		=	checker.c\
			instructions.c\
			stack.c\
			execute.c\
			quick_sort.c

INC		=	-I includes -I libft

OBJDIR	=	objs

OBJS	=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

LFT		=	libft/libft.a

CFLAGS	=	-Werror -Wall -Wextra

all : $(OBJDIR) $(NAME1)

$(OBJS): $(OBJDIR)/%.o: %.c
	gcc -c $(CFLAGS) $(INC) $< -o $@

$(OBJDIR):
	@mkdir -p $@

$(LFT):
	make -C libft/

$(NAME1): $(LFT) $(OBJS)
	cc $(CFLAGS) $^ -o $@ 
clean:
	make -C libft clean
	/bin/rm -rf $(OBJDIR)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME1)

re: fclean all
