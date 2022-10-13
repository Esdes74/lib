/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_queue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:46:25 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/13 16:52:26 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_QUEUE_H
# define LIB_QUEUE_H
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

void	init_queue();

#endif
