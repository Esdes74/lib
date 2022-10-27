/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:10:07 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/27 16:22:41 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

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

/*##################### LIST ##########################*/
void			init_list(void);

/*################### LIST_IND ########################*/
void			init_list_ind(void);

/*#################### QUEUE ##########################*/
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

/*##################### TREE ##########################*/
void			init_tree(void);

/*##################### GNRL ##########################*/
// Initialisation of data cells
t_data			*init_data(void *data, t_type t, t_bool allow, t_data *cell);

// Return size of type give to argument
// If a pointer is given as argument, return -1
long long int	size(t_type t, int debug);

/*##################### MATH ##########################*/
void			ft_power(void);

/*##################### STR ###########################*/
size_t			ft_strlen(char *str);

#endif
