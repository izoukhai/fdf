NAME= fdf

OBJ_PATH= ./obj/
SRC_PATH= ./

SRC_NAME = fdf.c main.c map.c utils.c draw.c hooks.c image.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDES= ./fdf.h libft/includes/get_next_line.h
FLAGS = -Wall -Werror -Wextra -O3

CC = gcc

all : $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJ) $(INCLUDES)
		@make -C libft/
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC) ./minilib/libmlx.a ./libft/libft.a -framework OpenGL -framework AppKit
		@echo "\033[32m[Your FdF is ready]\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
		@gcc $(FLAGS) -o $@ -c $^
clean :
		@rm -rf $(OBJ_PATH)
		@make clean -C libft/ 
		@echo "\033[0;32m [OK] \033[0m       \033[0;33m .o deleted:\033[0m" $<

fclean : clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ_PATH)
		@make fclean -C libft/
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m FdF deleted:\033[0m" $<

re : fclean all

.PHONY: clean re all fclean
