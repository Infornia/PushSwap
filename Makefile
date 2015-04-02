# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2015/03/25 20:49:52 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_PATH = ./obj/
SRC_PATH = ./

OBJ = $(SRC:.c=.o)
SRC = main.c\
	  push_swap.c\
	  ps_pile.c\
	  ps_ps.c\
	  ps_ss.c\
	  ps_r.c\
	  ps_rr.c\
	  ps_check_a.c\
	  ps_check_b.c\
	  ps_utils.c\
	  ps_utils2.c\
	  ps_options.c\

OBJS = $(addprefix $(OJB_PATH),$(OBJ))
SRCS = $(addprefix $(SRC_PATH),$(SRC))

PS_H = -I ./includes

all: $(NAME)

$(NAME):
	@gcc -g $(CFLAGS) $(PS_H) -c $(SRCS)
	@mkdir $(OBJ_PATH)
	@gcc -o $(NAME) $(OBJ)
	@mv $(OBJ) $(OBJ_PATH)
	@echo "\033[35m <(O.O<) WOW ! Very PushSwap ! Amaze ! (>^o^)> \033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

re: fclean all

.PHONY: all normal clean fclean re

