/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:42 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/11 15:08:48 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

void	stacking(t_list *lst, void *data, t_type t)
{
	t_data	*d_cell;
	t_cell	*cell;

	d_cell = 0;
	cell = (t_cell *) malloc(sizeof(t_cell));
	init_data(data, t, d_cell);
	cell->data_cell = d_cell;
	if (lst->len == 0)
		lst->tail = cell;
	else
		cell->next = lst->head;
	lst->len++;
	lst->head = cell;
}
