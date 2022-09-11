## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/09/11 15:53:16 by vgoncalv          #+#    #+#             ##
##   Updated: 2022/09/11 15:57:54 by vgoncalv         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME=philo/philo
MANDATORY=philo
BONUS=philo_bonus

all: $(NAME)

$(NAME):
	make -C $(MANDATORY)

bonus:
	make -C $(BONUS)

clean:
	make clean -C $(MANDATORY)
	make clean -C $(BONUS)

fclean:
	make fclean -C $(MANDATORY)
	make fclean -C $(BONUS)

re: fclean all

test:
	bash test.sh

test_bonus:
	bash test.sh --make-dir $(BONUS) --bin-path $(BONUS)/philo_bonus

.PHONY: all bonus clean fclean re test
