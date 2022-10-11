#!/bin/bash

echo "----------- NORMINETTE ----------"
norminette

echo "---------- COMPILATION ----------"
make 

# Compile with `-L` to include library
gcc -Wall -Wextra -Werror oracle.c -L. libft.a

echo "----------- EXECUTION -----------"
./oracle
