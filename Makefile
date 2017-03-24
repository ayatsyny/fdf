# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 20:21:23 by ayatsyny          #+#    #+#              #
#    Updated: 2017/03/21 19:16:10 by ayatsyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft.a
LIBFTPATH = ./libft
FLAGS = -Wall -Wextra -Werror
FLAGS_GR_LIB = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
        double_list.c \
        init_struct.c \
        tools_m_fdf.c \
        draw.c

HDR = fdf.h

OBJS = $(SRCS:.c=.o)

.PNONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	gcc $^ -o $(NAME) $(FLAGS_GR_LIB) $(LIBFTPATH)/$(LIBFT)

.c.o: $(SRCS)
	gcc $(FLAGS) -c $<

clean:
		make clean -C $(LIBFTPATH)
		rm -f $(OBJS)
		@echo OBJ_files is DEAD!!!

fclean: clean
		make fclean -C $(LIBFTPATH)
		rm -f $(NAME)
		@echo lib_files is DESTROYED!!!

re: fclean all
		@echo ALL DAMM is DESTROYED!!!

norm:
		make norm -C $(LIBFTPATH)
		norminette $(SRC) $(HDR) | grep -B 1 "Error"
