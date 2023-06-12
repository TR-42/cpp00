# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 21:02:13 by kfujita           #+#    #+#              #
#    Updated: 2023/06/12 21:37:14 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	megaphone

SRCS	:= \
	$(NAME).cpp\

override CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98

CXX		:=	c++

all:	$(NAME)

$(NAME):	$(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

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

fclean: clean_local
	rm -f $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	clean_local_obj
