/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:42 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/14 15:31:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

void	debugger(int debug, int mod)
{
	if (debug == 1)
	{
		if (mod == 0)
			write(1, "ERROR : fct stacking : Utilisation of fct stack on non \
					stack data structure\n", 77);
		if (mod == 1)
			write(1, "ERROR : fct stacking : Malloc not OK\n", 35);
	}
}

int	stacking(t_list *lst, void *data, t_type t, int debug)
{
	t_data	*d_cell;
	t_cell	*cell;

	if (lst->type_lst != STACK && debug == 1)
		debugger(debug, 0);
	if (lst->type_lst != STACK)
		return (0);
	d_cell = (t_data *) malloc(sizeof(t_data));
	cell = (t_cell *) malloc(sizeof(t_cell));
	if (debug == 1 && (d_cell == 0 || cell == 0))
		debugger(debug, 1);
	if (d_cell == 0 || cell == 0)
		return (0);
	init_data(data, t, d_cell);
	d_cell->allowed = FALSE;
	cell->data_cell = d_cell;
	if (lst->len == 0)
		lst->tail = cell;
	else
		cell->next = lst->head;
	lst->len++;
	lst->head = cell;
	return (1);
}
