/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:48:12 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/14 15:59:13 by eslamber         ###   ########.fr       */
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

void	*data_cpy(void *data)
{
	void	*new;
	size_t	i;
	size_t	size;
	int		*cpy_new;
	int		*cpy_data;

	size = sizeof(*data);
	new = malloc(size);
	cpy_new = (int *) new;
	cpy_data = (int *) data;
	i = 0;
	while (i < size)
		cpy_new[i] = cpy_data[i];
	new = (void *) cpy_new;
	return (new);
}

int	stacking_val(t_list *lst, void *data, t_type t, int debug)
{
	t_data	*d_cell;
	t_cell	*cell;
	void	*new_data;

	if (lst->type_lst != STACK && debug == 1)
		debugger(debug, 0);
	if (lst->type_lst != STACK)
		return (0);
	d_cell = (t_data *) malloc(sizeof(t_data));
	cell = (t_cell *) malloc(sizeof(t_cell));
	new_data = data_cpy(data);
	if (debug == 1 && (d_cell == 0 || cell == 0 || new_data == 0))
		debugger(debug, 1);
	if (d_cell == 0 || cell == 0 || new_data == 0)
		return (0);
	init_data(new_data, t, d_cell);
	d_cell->allowed = TRUE;
	cell->data_cell = d_cell;
	if (lst->len == 0)
		lst->tail = cell;
	else
		cell->next = lst->head;
	lst->len++;
	lst->head = cell;
	return (1);
}
