# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 21:02:13 by kfujita           #+#    #+#              #
#    Updated: 2023/06/19 21:04:05 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	megaphone

SRCS	:= \
	$(NAME).cpp\

OBJS	:= $(SRCS:.cpp=.o)
DEPS	:= $(OBJS:.o=.d)

override CXXFLAGS	+=	-Wall -Wextra -Werror -MMD -MP -std=c++98

CXX		:=	c++

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

debug:
	make CXXFLAGS='-DDEBUG -g'
faddr:
	make CXXFLAGS='-g -fsanitize=address'
fleak:
	make CXXFLAGS='-g -fsanitize=leak'

clean_local_obj:
	rm -f $(OBJS)

clean: clean_local_obj
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	clean_local_obj
