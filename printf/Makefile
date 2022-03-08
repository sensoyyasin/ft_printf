# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysensoy <ysensoy@student.42kocaeli.com.tr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 14:12:36 by ysensoy           #+#    #+#              #
#    Updated: 2022/03/08 13:50:41 by ysensoy          ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

SRC	= $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

clean:
			@rm -f *.o
			@make clean -C $(LIBFT)

fclean:		clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
