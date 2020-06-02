#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 16:05:19 by vpozniak          #+#    #+#              #
#    Updated: 2019/04/05 16:05:28 by vpozniak         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
INC = include/
LIBDIR = ./libft/
LIBFT = $(LIBDIR)libft.a
SRCDIR = src/
LSTDIR = src/coords_lst/
SRC = main.c move.c out.c pars.c strakt.c valid.c

SRCO = $(addprefix $(SRCDIR), $(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror -o
all: $(NAME)

$(LIBFT):
	make -C $(LIBDIR) --silent

$(NAME): $(LIBFT) $(SRCO) $(LSTO)
	gcc $(FLAGS) $(NAME) $(SRCO) $(LSTO) -L $(LIBDIR) -lft -I $(INC)

$(SRCDIR)%.o: $(SRCDIR)%.c
	gcc -c $(FLAGS) $@ $< -I $(INC)

$(LSTDIR)%.o: $(LSTDIR)%.c
	gcc -c $(FLAGS) $@ $< -I $(INC)

clean:
	make -C $(LIBDIR) clean --silent
	/bin/rm -f $(SRCO) $(LSTO)

fclean: clean
	make -C $(LIBDIR) fclean --silent
	/bin/rm -f $(NAME)

re: fclean all

rf: fclean all clean
