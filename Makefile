# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 13:46:52 by vfurmane          #+#    #+#              #
#    Updated: 2021/01/16 14:49:05 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c parse.c flags.c width.c
OBJS		= $(SRCS:.c=.o)
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
NAME		= libftprintf.a
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -I $(LIBFT_DIR) -o $@

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(AR) $@ $^

$(LIBFT):
			cd $(LIBFT_DIR) && make

clean:
			$(RM) $(OBJS)
			cd $(LIBFT_DIR) && make clean

fclean:		clean
			$(RM) $(NAME)
			cd $(LIBFT_DIR) && make fclean

re:			fclean all

.PHONY:		all clean fclean re
