# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 18:44:14 by klever            #+#    #+#              #
#    Updated: 2021/09/08 19:18:32 by kbarahon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL= srcs/gnl/get_next_line_bonus.c
NAME= fdf.a
SRC= $(GNL) ./srcs/fdf/utils.c ./srcs/fdf/utils_fdf.c ./srcs/fdf/read_map.c ./srcs/fdf/draw.c ./srcs/fdf/utils_draw.c
SRCB = ./srcs/fdf/fdf_bonus/key_code.c ./srcs/fdf/fdf_bonus/key_move.c ./srcs/fdf/fdf_bonus/screenshot.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
VAR = "42.fdf"

$(NAME):	$(OBJ)
	@make -sC ./srcs/libft/
	@cp ./srcs/libft/libft.a ./
	@make -sC ./srcs/minilibx/
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\033[42m"****************\\nCompiled...\\n****************\\n"\033[0m\n"

run:
	@clear
	@echo "\n\033[42m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@gcc -Wall -Wextra -Werror  fdf.c ./srcs/minilibx/libmlx.a -framework OpenGL -framework AppKit $(SRC) libft.a -o fdf
	@./fdf maps/$(VAR)

runbonus:
	@make bonus
	@echo "\n\033[42m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@./fdf maps/$(VAR)

all: $(NAME)

clean:
	@rm -f $(NAME) $(OBJ) ./src/code
	@make -sC ./srcs/minilibx/ clean
	@make -sC ./srcs/libft/ fclean
	@clear
	@echo "\n\033[42m"****************\\nDeleted files...\\n****************\\n"\033[0m\n"

bonus: 	all
		@clear
		@echo "\n\033[42m"****************\\nBonus...\\n****************\\n"\033[0m\n"
		@gcc -Wall -Wextra -Werror  $(SRC) $(SRCB) fdf_bonus.c ./srcs/minilibx/libmlx.a -framework OpenGL -framework AppKit  libft.a -o fdf

fclean: clean
		@rm -rf libft.a
		@rm -rf fdf
		@rm -rf fdf.a
		@rm -rf *.bmp


norm:
	@norminette $(SRC) 
	@norminette $(SRCB) 
	@norminette ./includes/*.h

re: clean all

.PHONY: all clean re run