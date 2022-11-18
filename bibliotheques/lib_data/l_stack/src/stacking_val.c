/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:48:12 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 11:49:09 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"
#include <stdio.h>

void	debugger_stacking_val(int debug, int mod)
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
	void	*cpy_new;
	/* void	*cpy_data; */

	size = sizeof(*data);
	printf("size = %ld\n", size);
	new = (int *) malloc(sizeof(int));
	/* cpy_new = (int *) cpy_new; */
	cpy_new = (int *) new;
	/* cpy_data = (int *) cpy_data; */
	/* cpy_data = (int *) data; */
	i = 0;
	while (i < size)
	{
		printf("i = %ld\n", i);
		/* cpy_new[i] = cpy_data[i]; */
		i++;
	}
	new = (void *) cpy_new;
	return (new);
}

int	stacking_val(t_list *lst, void *data, t_type t, int debug)
{
	t_data	*d_cell;
	t_cell	*cell;
	void	*new_data;

	if (lst->type_lst != STACK && debug == 1)
		debugger_stacking_val(debug, 0);
	if (lst->type_lst != STACK)
		return (0);
	d_cell = (t_data *) malloc(sizeof(t_data));
	cell = (t_cell *) malloc(sizeof(t_cell));
	new_data = data_cpy(data);
	if (debug == 1 && (d_cell == 0 || cell == 0 || new_data == 0))
		debugger_stacking_val(debug, 1);
	if (d_cell == 0 || cell == 0 || new_data == 0)
		return (0);
	init_data(new_data, t, TRUE, d_cell);
	cell->data_cell = d_cell;
	if (lst->len == 0)
		lst->tail = cell;
	else
		cell->next = lst->head;
	lst->len++;
	lst->head = cell;
	return (1);
}
