## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/09/05 16:57:33 by vgoncalv          #+#    #+#             ##
##   Updated: 2022/09/05 17:39:53 by vgoncalv         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = t_project

CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = ./build

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L./libft -lft
LIBFT_INCLUDES_DIR = ./libft/include ./libft

INCLUDES_DIR = $(LIBFT_INCLUDES_DIR) ./src
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))

vpath %.c src
SRCS = main.c
OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:%.c=%.o)) 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBFT_FLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJDIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re so
