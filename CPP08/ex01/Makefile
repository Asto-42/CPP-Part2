# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquil <jquil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 16:46:22 by aboulest          #+#    #+#              #
#    Updated: 2024/06/11 13:43:57 by jquil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Span

CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -MMD -std=c++98 -g3

SRC			:= 	main.cpp	\
				Span.cpp	\


OBJ_DIR 	:= ./objs/
C_OBJ_DIR	:= @mkdir -p $(OBJ_DIR)
OBJ			:=$(SRC:.cpp=.o)
OBJ			:=$(addprefix $(OBJ_DIR), $(OBJ))

DEPS		:=$(OBJ:.o=.d)

###########################################################

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADER)
	$(C_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

debug: FLAGS += -D DEBUG
debug: re

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

-include $(DEPS)
