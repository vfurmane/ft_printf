# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 11:23:33 by vfurmane          #+#    #+#              #
#    Updated: 2021/01/09 19:56:39 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(addprefix ft_, atoi.c bzero.c calloc.c isalnum.c isalpha.c \
			  isascii.c isdigit.c isprint.c itoa.c memccpy.c memchr.c memcmp.c \
			  memcpy.c memmove.c memset.c putchar_fd.c putendl_fd.c \
			  putnbr_fd.c putstr_fd.c split.c strchr.c strdup.c strjoin.c \
			  strlcat.c strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c \
			  strrchr.c strtrim.c substr.c tolower.c toupper.c)
OBJS		= $(SRCS:.c=.o)
BON_SRCS	= $(addprefix ft_, lstadd_back.c lstadd_front.c lstclear.c \
			  lstdelone.c lstiter.c lstlast.c lstmap.c lstnew.c lstsize.c)
BON_OBJS	= $(BON_SRCS:.c=.o)
INCL		= .
NAME		= libft.a
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
AR			= ar -rcs
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -I $(INCL) -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

bonus:		all $(NAME) $(BON_OBJS)
			$(AR) $(NAME) $(BON_OBJS)

clean:
			$(RM) $(OBJS) $(BON_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
