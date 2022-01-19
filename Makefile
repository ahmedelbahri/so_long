# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 16:22:28 by ahel-bah          #+#    #+#              #
#    Updated: 2022/01/19 16:42:38 by ahel-bah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

F = -Wall -Wextra -Werror

NAME = so_long

SRC = so_long.c utils/ft_strlen.c utils/ft_arg_check.c \
	  utils/ft_strrchr_ber.c utils/ft_map.c utils/ft_lencmp.c \
	  utils/ft_mapcheck.c utils/ft_substr.c utils/ft_strdup.c \
	  utils/ft_splite.c utils/ft_strjoin.c utils/hooks/key_hook.c \
	  utils/hooks/ft_down.c utils/hooks/ft_free_map.c utils/hooks/ft_left.c \
	  utils/hooks/ft_right.c utils/hooks/ft_up.c utils/ft_strcmp.c \
	  utils/hooks/ft_close.c

OBJ = $(SRC:.c=.o)

BNS = so_long_bonus.c utils_bonus/ft_strlen.c utils_bonus/ft_arg_check.c \
	  utils_bonus/ft_strrchr_ber.c utils_bonus/ft_map.c \
	  utils_bonus/ft_lencmp.c utils_bonus/ft_mapcheck.c \
	  utils_bonus/ft_substr.c utils_bonus/ft_strdup.c \
	  utils_bonus/ft_splite.c utils_bonus/ft_strjoin.c \
	  utils_bonus/hooks/key_hook.c utils_bonus/hooks/ft_down.c \
	  utils_bonus/hooks/ft_free_map.c utils_bonus/hooks/ft_left.c \
	  utils_bonus/hooks/ft_right.c utils_bonus/ft_itoa.c\
	  utils_bonus/hooks/ft_up.c utils_bonus/ft_strcmp.c \
	  utils_bonus/hooks/ft_close.c utils_bonus/loop_animator.c \
	  utils_bonus/ft_lstclear.c

B_OBJ = $(BNS:.c=.o)

all : $(NAME)

%.o: %.c
	@$(C) $(F) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(C) $(F) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME);

bonus: $(B_OBJ)
	@$(C) $(F) $(B_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME);

clean:
	@rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all