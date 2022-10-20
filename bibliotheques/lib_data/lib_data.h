/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:38:47 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/20 17:06:17 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DATA_H
# define LIB_DATA_H
# include <stdlib.h>
# include <unistd.h>

typedef enum e_type {
	CHAR,
	INT,
	STRING,
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

typedef enum e_bool{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_data {
	t_type	type_data;
	t_bool	allowed;
	void	*data;
}	t_data;

typedef struct s_cell {
	t_data			*data_cell;
	struct s_cell	*next;
}	t_cell;

typedef struct s_list {
	size_t	len;
	t_type	type_list;
	t_cell	*head;
	t_cell	*tail;
}	t_list;

// Prototype
typedef struct s_head_tree {
	size_t	len_uplet;
	t_data	*data;
	t_list	*leaves;
}	t_tree;

/*####################### LIST ########################*/
void	init_list();

/*##################### LIST_IND ######################*/
void	init_list_ind();

/*###################### QUEUE ########################*/
void	init_queue();

/*###################### STACK ########################*/
// Initialisation of queue list
t_list	*init_stack(t_type t, t_list *lst);

// Add element on first index of list
int		stacking(t_list *lst, void *data, t_type t, int debug);

// Add copy of variable on first index of list
int		stacking_val(t_list *lst, void *data, t_type t, int debug);

// Remove first element and return it
t_cell	*unstack(t_list *lst, int debug);

// Remove first element and destroy it
void	rmstack(t_list *lst, int debug);

/*####################### TREE ########################*/
void	init_tree();

/*####################### GNRL ########################*/
// Initialisation of data cells
t_data	*init_data(void *data, t_type t, t_bool allow, t_data *cell);

// Return size of type give to argument
// If a pointer is given as argument, return -1
size_t	size(t_type t, int debug);

#endif
