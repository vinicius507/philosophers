## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/09/05 16:57:33 by vgoncalv          #+#    #+#             ##
##   Updated: 2022/09/09 14:37:29 by vgoncalv         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
BUILD_DIR = ./build

SRC_DIR = ./src
INCLUDES_DIR = $(SRC_DIR)
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))
LIBS = -pthread

vpath %.c $(SRC_DIR)
SRCS = philo_bonus.c strings_bonus.c error_bonus.c args_bonus.c time_bonus.c \
	   philos_bonus.c starved_bonus.c sem_bonus.c die_bonus.c log_bonus.c \
	   eat_bonus.c sleep_bonus.c simulation_bonus.c
OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:%.c=%.o)) 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re so
