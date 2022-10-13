# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:18:56 by eslamber          #+#    #+#              #
#    Updated: 2022/10/13 17:18:17 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Declarations of variables
#

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definition of repertories
SRC := src/
OBJ := obj/

# Definitions of variables
LIB := lib_list_ind.a
H := lib_list_ind.h

L_SRC := init_list_ind.c
L_OBJ := $(L_SRC:%.c=$(OBJ)%.o)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'

#
### Compilations rules
#

all: $(LIB)

$(LIB): $(L_OBJ)
	ar rc $@ $^
	ranlib $@

$(L_OBJ): $(OBJ)%.o: $(SRC)%.c $(H)
	$(CC) $(FLAGS) -c $< -o $@

#
### Directories rules
#

dir:
	@echo -e $(LIGHTBLUE)make objects files directories$(NEUTRAL)
	mkdir -p $(OBJ)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

#
### Print rules
#

# Compilation of librairie with print options
print: print_ob $(L_OBJ) print_lb $(LIB) print_le

print_ob:
	@echo -e $(LIGHTBLUE)compilation lib objects files$(NEUTRAL)

print_oe:
	@echo -e $(LIGHTBLUE)compilation lib objetcs files done$(NEUTRAL)
	@echo

print_lb: print_oe
	@echo -e $(LIGHTBLUE)compilation librairie$(NEUTRAL)

print_le:
	@echo -e $(LIGHTBLUE)compilation librairie done$(NEUTRAL)
	@echo

#
### Test rule
#

vartest:
	@echo "L_OBJ = $(L_OBJ)"

#
### Cleanup rules
#

# Classiques cleaning rules
clean:
	@echo -e $(LIGHTBLUE)remove all $(RED)librairires objects files$(NEUTRAL)
	@rm -v $(L_OBJ)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -v $(LIB)
	@echo

# Directories cleaning rules
cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)librairies directories$(NEUTRAL)
	@rm -rfv $(OBJ)
	@echo

# Full cleaning rules
fclean: clean cleanlib cleandir dir

# Remake rules
re: fclean all

# Remakes rules with print options
reprint: fclean print

.PHONY: print_oe print_ob print_le print_lb reprint print
.PHONY: re all dir
.PHONY: fclean clean cleanlib cleandir
