/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:10:07 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/10 15:17:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef enum e_type {
	CHAR,
	INT,
	DOUBLE,
	LONG,
	UNSIGNED,
	LONG_LONG,
	LONG_UNSIGNED,
	LONG_LONG_UNSIGNED,
	LIST,
	LIST_IND,
	STACK,
	PILE,
	DICO,
	TREE,
	ALEA
}	t_type;

typedef struct s_data {
	t_type	type_data;
	void	*data
}	t_data;

typedef struct s_cell {
	t_data			*data_cell;
	struct s_cell	*next;
}	t_cell;

typedef struct s_list {
	size_t	len;
	t_type	type_lst;
	t_cell	*head;
	t_cell	*tail;
}	t_list;

// Prototype
typedef struct s_head_tree {
	size_t	len_uplet;
	t_data	*data;
	t_list	*leaves
}	t_tree;

// LIB_LIST_H
void	init_list();

// LIB_LIST_IND_H
void	init_list_ind();

// LIB_PILE_H
void	init_pile();

// LIB_STACK_H
void	init_stack();

// LIB_TREE_H
void	init_tree();

// LIB_MATH_H
void	ft_power();

// LIB_STR_H
size_t	ft_strlen(char *str);

#endif
