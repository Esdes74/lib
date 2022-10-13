/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list_ind.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:09:34 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/13 16:52:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIST_IND_H
# define LIB_LIST_IND_H
# include <stdlib.h>

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

void	init_list_ind();

#endif
