/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:38:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 12:01:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DATA_H
# define LIB_DATA_H
# include <stdlib.h>
# include <unistd.h>
# include "l_simple/lib_simple.h"

typedef enum e_type {
	CHAR = 0,
	INT = 1,
	STRING = 2,
	DOUBLE = 3,
	LONG = 4,
	UNSIGNED = 5,
	LONG_LONG = 6,
	LONG_UNSIGNED = 7,
	LONG_LONG_UNSIGNED = 8,
	LIST = 9,
	LIST_IND = 10,
	STACK = 11,
	QUEUE = 12,
	DICO = 13,
	TREE = 14,
	ALEA = 15
}	t_type;

typedef enum e_bool{
	FALSE = 0,
	TRUE = 1
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
	t_type	type_lst;
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
// Initailisation of head of list
t_list			*init_list(t_list *lst);

// Stacking values in a list (add in first place)
int				stacking_list(t_list *lst, void *data, t_type t, int debug);

// Add value in a list (add in last place)
int				addback_list(t_list *lst, void *data, t_type t, int debug);

// remove cell from the front of list and return it
t_cell			*unstack_list(t_list *lst, int debug);

// Remove cell from the front of list and free it
void			rmstack_list(t_list *lst, t_bool allow, int debug);

// Remove cell from the back of list and return it
t_cell	*rmback_list(t_list *lst, int debug);

// Remove cell from the back of list and free it
void	delback_list(t_list *lst, t_bool allow, int debug);

/*##################### LIST_IND ######################*/
void			init_list_ind(void);

/*###################### QUEUE ########################*/
void			init_queue(void);

/*###################### STACK ########################*/
// Initialisation of queue list
t_list			*init_stack(t_list *lst);

// Add element on first index of list
int				stacking(t_list *lst, void *data, t_type t, int debug);

// Add copy of variable on first index of list
int				stacking_val(t_list *lst, void *data, t_type t, int debug);

// Remove first element and return it
t_cell			*unstack(t_list *lst, int debug);

// Remove first element and destroy it
void			rmstack(t_list *lst, t_bool allow, int debug);

/*####################### TREE ########################*/
void			init_tree(void);

/*####################### GNRL ########################*/
// Initialisation of data cells
t_data			*init_data(void *data, t_type t, t_bool allow, t_data *cell);

// Return size of type give to argument
// If a pointer is given as argument, return -1
long long int	size(t_type t, int debug);

#endif
