# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:42:31 by eslamber          #+#    #+#              #
#    Updated: 2022/10/11 11:09:36 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definitions of tests repositories
TEST_DIR := ../test_lib/
TEST_OBJ_DIR := $(TEST_DIR)obj/
TEST_SRC_DIR := $(TEST_DIR)src/
TEST_EXE_DIR := $(TEST_DIR)exe/

# Definitions of variables needed for test compilation
SRC_TEST := oracle.c \
			list.c
EXE := oracle
NAME := $(EXE:%=$(TEST_EXE_DIR)%)

# Definition of test's objects files
OBJ_TEST := $(SRC_TEST:%.c=$(TEST_OBJ_DIR)%.o)

# Definition of variable librairie
LIB := libft.a

# Definitions of librairies repositories
LIB_FCT := lib_fct/
LIB_DATA := lib_data/

LIB_LIST := $(LIB_DATA)l_list/
LIB_LIST_SRC := $(LIB_LIST)src/
LIB_LIST_OBJ := $(LIB_LIST)obj/

LIB_LIST_IND := $(LIB_DATA)l_list_ind/
LIB_LIST_IND_SRC := $(LIB_LIST_IND)src/
LIB_LIST_IND_OBJ := $(LIB_LIST_IND)obj/

LIB_PILE := $(LIB_DATA)l_pile/
LIB_PILE_SRC := $(LIB_PILE)src/
LIB_PILE_OBJ := $(LIB_PILE)obj/

LIB_STACK := $(LIB_DATA)l_stack/
LIB_STACK_SRC := $(LIB_STACK)src/
LIB_STACK_OBJ := $(LIB_STACK)obj/

LIB_TREE := $(LIB_DATA)l_tree/
LIB_TREE_SRC := $(LIB_TREE)src/
LIB_TREE_OBJ := $(LIB_TREE)obj/

LIB_MATH := $(LIB_FCT)lib_math/
LIB_MATH_SRC := $(LIB_MATH)src/
LIB_MATH_OBJ := $(LIB_MATH)obj/

LIB_STR := $(LIB_FCT)lib_str/
LIB_STR_SRC := $(LIB_STR)src/
LIB_STR_OBJ := $(LIB_STR)obj/

ALL_LIB_OBJ_DIR := $(LIB_LIST_OBJ) \
				   $(LIB_LIST_IND_OBJ) \
				   $(LIB_PILE_OBJ) \
				   $(LIB_STACK_OBJ) \
				   $(LIB_TREE_OBJ) \
				   $(LIB_MATH_OBJ) \
				   $(LIB_STR_OBJ)

ALL_LIB_SRC_DIR := $(LIB_LIST_SRC) \
				   $(LIB_LIST_IND_SRC) \
				   $(LIB_PILE_SRC) \
				   $(LIB_STACK_SRC) \
				   $(LIB_TREE_SRC) \
				   $(LIB_MATH_SRC) \
				   $(LIB_STR_SRC)

# Definition of variables needed to librairie's compilation
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

MATH_LIB := ft_power.c
MATH_LIB_H := $(LIB_MATH)lib_math.h
MATH_OBJ_LIB := $(MATH_LIB:%.c=$(LIB_MATH_OBJ)%.o)

STR_LIB := ft_strlen.c
STR_LIB_H := $(LIB_STR)lib_str.h
STR_OBJ_LIB := $(STR_LIB:%.c=$(LIB_STR_OBJ)%.o)

ALL_OBJ_LIB := $(LIST_OBJ_LIB) \
			   $(LIST_IND_OBJ_LIB) \
			   $(PILE_OBJ_LIB) \
			   $(STACK_OBJ_LIB) \
			   $(TREE_OBJ_LIB) \
			   $(MATH_OBJ_LIB) \
			   $(STR_OBJ_LIB)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'

# Compilations rules
# only lib
all: $(LIB)

# lib and test
test: $(LIB) $(NAME)

$(LIB): $(ALL_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(NAME): $(OBJ_TEST)
	$(CC) $(FLAGS) -o $@ $^ -L. $(LIB)

$(OBJ_TEST): $(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

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

$(MATH_OBJ_LIB): $(LIB_MATH_OBJ)%.o: $(LIB_MATH_SRC)%.c $(MATH_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

$(STR_OBJ_LIB): $(LIB_STR_OBJ)%.o: $(LIB_STR_SRC)%.c $(STR_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

#
### Directories rules
#

make_dir: dir_lib dir_test

dir_lib:
	@echo -e $(LIGHTBLUE)make librairies directories$(NEUTRAL)
	mkdir -p $(ALL_LIB_OBJ_DIR)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

dir_test:
	@echo -e $(LIGHTBLUE)make test directories$(NEUTRAL)
	mkdir -p $(TEST_OBJ_DIR) $(TEST_EXE_DIR)
	@echo -e $(LIGHTBLUE)done
	@echo -e $(NEUTRAL)

#
### Test rules
#

vartest:
	echo $(ALL_LIB_OBJ_DIR)

#
### Prints rules
#

# Compilation of librairie with print options
printlib: print_ob $(ALL_OBJ_LIB) print_lb $(LIB) print_le

# Compilation of tests with print options
printtest: print_otb $(OBJ_TEST) print_eb $(NAME) print_ee

print: printlib printtest

print_ob:
	@echo -e $(LIGHTBLUE)compilation lib objects files$(NEUTRAL)

print_oe:
	@echo -e $(LIGHTBLUE)compilation lib objetcs files done$(NEUTRAL)
	@echo

print_otb:
	@echo -e $(LIGHTBLUE)compilation test objects files$(NEUTRAL)

print_ote:
	@echo -e $(LIGHTBLUE)compilation test objetcs files done$(NEUTRAL)
	@echo

print_eb: print_ote
	@echo -e $(LIGHTBLUE)compilation executables$(NEUTRAL)

print_ee:
	@echo -e $(LIGHTBLUE)compilation executables done$(NEUTRAL)
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
	@echo -e $(LIGHTBLUE)remove all $(RED)objects files$(NEUTRAL)
	@rm -v $(OBJ_TEST) $(ALL_OBJ_LIB)
	@echo

cleanobjlib:
	@echo -e $(LIGHTBLUE)remove all $(RED)librairires objects files$(NEUTRAL)
	@rm -v $(ALL_OBJ_LIB)
	@echo

cleanobjexec:
	@echo -e $(LIGHTBLUE)remove all $(RED)executables objects files$(NEUTRAL)
	@rm -v $(OBJ_TEST)
	@echo

cleanexec: 
	@echo -e $(LIGHTBLUE)remove all $(RED)executables$(NEUTRAL)
	@rm -v $(NAME)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -v $(LIB)
	@echo

# Directories cleaning rules
cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)directories$(NEUTRAL)
	@rm -rfv $(TEST_OBJ_DIR) $(TEST_EXE_DIR) $(ALL_LIB_OBJ_DIR)
	@echo

cleandirlib: 
	@echo -e $(LIGHTBLUE)remove all $(RED)librairies directories$(NEUTRAL)
	@rm -rfv $(ALL_LIB_OBJ_DIR)
	@echo

cleandirtest: 
	@echo -e $(LIGHTBLUE)remove all $(RED)executables directories$(NEUTRAL)
	@rm -rfv $(TEST_OBJ_DIR) $(TEST_EXE_DIR)
	@echo

# Full cleaning rules
fclean: cleanobjlib cleanobjexec cleanlib cleanexe cleandir make_dir

fcleanlib: cleanobjlib bcleandirlib cleanlib dir_lib

fcleantest: fclean dir_test

# Remake rules
re: fcleanlib all

retest: fclean test

# Remakes rules with print options
reprint: fcleanlib printlib

reprinttest: fclean print

.PHONY: print_oe print_eb print_ee print_ob print_le print_lb reprint print
.PHONY: print_otb print_ote reprinttest
.PHONY: re dir_lib dir_test vartest all test make_dir retest
.PHONY: fcleantest cleandirtest fclean clean cleandir cleanlib cleanexec 
.PHONY: fcleanlib cleandirlib cleanobjlib cleanobjexec
