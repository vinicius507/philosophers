## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/09/05 16:57:33 by vgoncalv          #+#    #+#             ##
##   Updated: 2022/09/06 13:21:19 by vgoncalv         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = ./build

SRC_DIR = ./src
INCLUDES_DIR = $(SRC_DIR)
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))
LIBS = -lpthread

vpath %.c $(SRC_DIR)
SRCS = philo.c strings.c args.c forks.c philosophers.c simulation.c
OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:%.c=%.o)) 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re so
