# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 08:51:22 by ttshivhu          #+#    #+#              #
#    Updated: 2017/12/05 10:10:59 by ttshivhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = npuzzle

SRC = main.c solvable.c astar_algo.c reader.c goal.c get_next_line.c list.c heuristics.c queue.c random.c \

FLAG = -g3 -Wall -Werror -Wextra

SILENT = --no-print-directory

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
	@make -C libft $(SILENT)
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) $(OBJ)  libft/libft.a -lreadline -o $(NAME)
	@printf "\x1b[32mCompiled $(NAME) 👍\x1b[0m\n"

clean:
	@make clean -C libft $(SILENT)
	@/bin/rm -f $(OBJ) $(LOBJ) *.o
	@printf "\x1b[31mRemoved object files\x1b[0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft $(SILENT)
	@printf "\x1b[31mRemoved $(NAME)\x1b[0m\n"

re: fclean all
