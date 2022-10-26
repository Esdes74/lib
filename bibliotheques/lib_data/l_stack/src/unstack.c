/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:52:09 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/26 16:36:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"
#include <stdio.h>

t_cell	*unstack(t_list *lst, int debug)
{
	t_cell	*rm;

	if (lst->type_lst != STACK)
	{
		if (debug == 1)
		{
			write(1, "ERROR : fct unstack : Utilisation of fct stack on", 49);
			write(1, "non stack data structure\n", 25);
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
	else
		rm = 0;
	lst->len--;
		write(1, "print test unstack\n", 19);
	return (rm);
}
