/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstack_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:17:06 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/03 20:20:34 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_cell	*unstack_list(t_list *lst, int debug)
{
	t_cell	*rm;

	rm = 0;
	if (lst->type_lst != LIST)
	{
		if (debug == 1)
		{
			write(1, "ERROR : fct unstack_list : Utilisation of fct list", 45);
			write(1, " on non list data structure\n", 28);
		}
		return (0);
	}
	if (lst->len > 0)
	{
		rm = lst->head;
		lst->head = rm->next;
	}
	if (lst->len == 1)
		lst->tail = 0;
	lst->len--;
	return (rm);
}
