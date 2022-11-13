# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 19:00:05 by ciclo             #+#    #+#              #
#    Updated: 2022/10/31 15:03:20 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT := client

NAME_SERVER := server

SRC_DIR := src/
OBJ_DIR := obj/
CC 		:= gcc
CFLAGS 	:= -Wall -Werror -Wextra
RM 		:= rm -rf

SANI 	:= -fsanitize=address -g3
val 	:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#server
SRC_FILES_S := utils server

src_s := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_S)))
#obj_s := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_S)))
#client
SRC_FILES_C := utils client

src_c := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_C)))
#obj_c := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_C)))
#rules of memory leaks
$(NAME_CLIENT) $(NAME_SERVER): #$(obj_c) $(obj_s)
				make -C ft_printf
				mv ft_printf/ft_printf.a .
				$(CC) $(CFLAGS) $(src_c) ft_printf.a  -o $(NAME_CLIENT)
				$(CC) $(CFLAGS) $(src_s) ft_printf.a  -o $(NAME_SERVER)
# necesito crear la regla de lo objetos aunque de esta forma no  hace falta porque los conviertos en client y en server directamente pero esta guay intentarlo para practicar la creacion de archivos makefile

all: $(NAME_CLIENT) $(NAME_SERVER)

clean:
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)

fclean: clean
		make fclean -C ft_printf
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
