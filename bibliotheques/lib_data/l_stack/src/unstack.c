/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:52:09 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/06 20:28:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"
#include <stdio.h>

t_cell	*unstack(t_list *lst, int debug)
{
	t_cell	*rm;

	rm = lst->head;
	if (lst->type_lst != STACK || lst->len == 0)
	{
		if (debug == 1 && lst->type_lst != STACK)
		{
			write(1, "ERROR : fct unstack : Utilisation of fct stack on", 49);
			write(1, " non stack data structure\n", 26);
		}
		return (0);
	}
	if (lst->len > 0)
		lst->head = rm->next;
	if (lst->len > 1)
		lst->head->prev = 0;
	if (lst->len == 1)
		lst->tail = 0;
	lst->len--;
	return (rm);
}
