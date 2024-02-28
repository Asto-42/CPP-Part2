# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 11:58:31 by jquil             #+#    #+#              #
#    Updated: 2024/02/21 13:10:40 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	main.cpp						\
			Base.cpp						\
			A.cpp							\
			B.cpp							\
			C.cpp							\

NAME		=	IRT
OBJS		=	$(SRC:.cpp=.o)

COMPILE		=	clang++

FLAGS		=	-Wall -Wextra -Werror -std=c++98 -std=c++11

EXE_NAME	=	-o $(NAME)

EXEC		=	$(NAME)

# ------------------------------------- RULES ---------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) $(EXE_NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(EXEC)

re:	fclean all

.cpp.o:
	${COMPILE} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY:	all clean fclean re run
