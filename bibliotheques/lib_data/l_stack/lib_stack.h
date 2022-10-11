/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:45:08 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/11 15:30:19 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STACK_H
# define LIB_STACK_H
# include <stdlib.h>

typedef enum e_type {
	CHAR,
	STRING,
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
	QUEUE,
	DICO,
	TREE,
	ALEA
}	t_type;

typedef struct s_data {
	t_type	type_data;
	void	*data;
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

// Initialisation of data cells
t_data	*init_data(void *data, t_type t, t_data *cell);

// Initialisation of queue list
t_list	*init_stack(t_type t, t_list *lst);

// Add element on first index of list
int		stacking(t_list *lst, void *data, t_type t);

// Remove first element and return it
t_cell	*unstack(t_list *lst);

// Remove first element and destroy it
void	rmstack(t_list *lst);

#endif
