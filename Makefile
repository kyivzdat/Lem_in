# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 14:48:20 by vpalamar          #+#    #+#              #
#    Updated: 2019/07/24 14:48:21 by vpalamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIBDIR = ./libft

SRC :=	main.c \
		parse.c \
		parse1.c \
		parse2.c \
		lists.c \
		path.c \
		print.c \
		tools_queue.c \
		tools.c \
		way.c \

LIB = $(LIBDIR)/libft.a

O_FILES := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) -C $(LIBDIR)
	gcc -g -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

%.o: %.c filler.h
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(O_FILES)
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBDIR)

re: fclean all
