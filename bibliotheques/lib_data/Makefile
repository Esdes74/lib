# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 10:46:11 by eslamber          #+#    #+#              #
#    Updated: 2022/10/11 11:17:36 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definitions of librairies repertories
LIB_LIST := l_list/
LIB_LIST_SRC := $(LIB_LIST)src/
LIB_LIST_OBJ := $(LIB_LIST)obj/

LIB_LIST_IND := l_list_ind/
LIB_LIST_IND_SRC := $(LIB_LIST_IND)src/
LIB_LIST_IND_OBJ := $(LIB_LIST_IND)obj/

LIB_PILE := l_pile/
LIB_PILE_SRC := $(LIB_PILE)src/
LIB_PILE_OBJ := $(LIB_PILE)obj/

LIB_STACK := l_stack/
LIB_STACK_SRC := $(LIB_STACK)src/
LIB_STACK_OBJ := $(LIB_STACK)obj/

LIB_TREE := l_tree/
LIB_TREE_SRC := $(LIB_TREE)src/
LIB_TREE_OBJ := $(LIB_TREE)obj/

ALL_LIB_OBJ_DIR := $(LIB_LIST_OBJ) \
				   $(LIB_LIST_IND_OBJ) \
				   $(LIB_PILE_OBJ) \
				   $(LIB_STACK_OBJ) \
				   $(LIB_TREE_OBJ)

ALL_LIB_SRC_DIR := $(LIB_LIST_SRC) \
				   $(LIB_LIST_IND_SRC) \
				   $(LIB_PILE_SRC) \
				   $(LIB_STACK_SRC) \
				   $(LIB_TREE_SRC)

# Definition of variables needed for librairie compilation

LIB := lib_data.a

LIST_LIB := init_list.c
LIST_LIB_H := $(LIB_LIST)lib_list.h
LIST_OBJ_LIB := $(LIST_LIB:%.c=$(LIB_LIST_OBJ)%.o)

LIST_IND_LIB := init_list_ind.c
LIST_IND_LIB_H := $(LIB_LIST_IND)lib_list_ind.h
LIST_IND_OBJ_LIB := $(LIST_IND_LIB:%.c=$(LIB_LIST_IND_OBJ)%.o)

PILE_LIB := init_pile.c
PILE_LIB_H := $(LIB_PILE)lib_pile.h
PILE_OBJ_LIB := $(PILE_LIB:%.c=$(LIB_PILE_OBJ)%.o)

STACK_LIB := init_stack.c
STACK_LIB_H := $(LIB_STACK)lib_stack.h
STACK_OBJ_LIB := $(STACK_LIB:%.c=$(LIB_STACK_OBJ)%.o)

TREE_LIB := init_tree.c
TREE_LIB_H := $(LIB_TREE)lib_tree.h
TREE_OBJ_LIB := $(TREE_LIB:%.c=$(LIB_TREE_OBJ)%.o)

ALL_OBJ_LIB := $(LIST_OBJ_LIB) \
			   $(LIST_IND_OBJ_LIB) \
			   $(PILE_OBJ_LIB) \
			   $(STACK_OBJ_LIB) \
			   $(TREE_OBJ_LIB)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'

# Compilations rules
all: $(LIB)

$(LIB): $(ALL_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(LIST_OBJ_LIB): $(LIB_LIST_OBJ)%.o: $(LIB_LIST_SRC)%.c $(LIST_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

$(LIST_IND_OBJ_LIB): $(LIB_LIST_IND_OBJ)%.o: $(LIB_LIST_IND_SRC)%.c \
$(LIST_IND_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

$(PILE_OBJ_LIB): $(LIB_PILE_OBJ)%.o: $(LIB_PILE_SRC)%.c $(PILE_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

$(STACK_OBJ_LIB): $(LIB_STACK_OBJ)%.o: $(LIB_STACK_SRC)%.c $(STACK_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

$(TREE_OBJ_LIB): $(LIB_TREE_OBJ)%.o: $(LIB_TREE_SRC)%.c $(TREE_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

#
### Directories rules
#

dir:
	@echo -e $(LIGHTBLUE)make librairies directories$(NEUTRAL)
	mkdir -p $(ALL_LIB_OBJ_DIR)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

# Compilation of librairie with print options
print: print_ob $(ALL_OBJ_LIB) print_lb $(LIB) print_le

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
### Cleanup rules
#

# Classiques cleaning rules
clean:
	@echo -e $(LIGHTBLUE)remove all $(RED)librairires objects files$(NEUTRAL)
	@rm -v $(ALL_OBJ_LIB)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -v $(LIB)
	@echo

# Directories cleaning rules
cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)librairies directories$(NEUTRAL)
	@rm -rfv $(ALL_LIB_OBJ_DIR)
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
