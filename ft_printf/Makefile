# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:00:13 by ciclo             #+#    #+#              #
#    Updated: 2022/10/31 15:00:28 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_printf.a
INCLUDE		:= include
LIBFT		:= libft
SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -I
RM			:= rm -f
AR			:= ar rcs
# rules of memory leaks
val :=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

SANI := -fsanitize=address -g3

SRC_FILES	:=	 ft_print_int  ft_printf ft_printf_utils ft_printf_hex ft_printf_p

SRC	:= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ	:= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
#.SILENT:
#Rules of compilation and linking of the library and the executable file
$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			echo "$(GREEN)ft_printf compilando!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			mkdir  $(OBJ_DIR) 2> /dev/null || true
			 @echo "$(GREEN)Creando la carpeta de objetos $<$(RESET)"
# /dev/null to avoid error message if the directory already exists
			echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:		$(NAME)

clean:
			$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)ft_printf limpiando objetos!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"
cache:
	@mkdir -p $(OBJ_DIR)

re:		fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

sanitize:
	$(CC) $(SANI) $(SRC) main.c -I $(INCLUDE)  -lft -o $(NAME)
	@echo "$(GREEN)Sanitize compilando!$(RESET)"

valgrind:

	$(val)	./libftprintf.a
	@echo "\n valgind in use xd\n"

comp: all

	$(CC) test/main.c $(NAME)  -o main.o && ./main.o && rm -rf *.o
#@echo "\n compilation done \n"

.PHONY:		all clean fclean re norm
