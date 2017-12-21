# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 00:51:14 by gsysaath          #+#    #+#              #
#    Updated: 2017/12/14 00:21:47 by gsysaath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GG = gcc

CFLAG = -Wall -Wextra -Werror ##-O1 -g -fsanitize=address -fno-omit-frame-pointer -fsanitize-address-use-after-scope

NAME = fillit

SRC = main.c \
	  final.c \
	  sauverpieces.c \
	  verification.c \
	  display.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  deletemalloc.c \
	  ft_puterror.c \
	  tableaupieces.c \

HEAD = libft.h \
	   header.h \


RM = rm -f

OBJ = $(SRC:.c=.o) 

%.o: %.c
	@echo "\033[1;32;m[$<]\033[0m : " | tr -d '\n'
	$(GG) $(CFLAG) -c $<

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(GG) $(CFLAG) -o $@ $(OBJ)
	@echo "\033[1;32;m[Compilation Successful]\033[0m"
	@echo "\033[1;36;m$(NAME)\033[1;32;m ready to go !\033[0m"

clean:
	@echo "\033[0;33;m[Clean]\033[0m              : " | tr -d '\n'
	rm -f $(OBJ)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAME)]\033[0m : " | tr -d '\n'
	rm -f $(NAME)

re: fclean all
