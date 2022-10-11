/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:52:09 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/11 15:09:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

t_cell	*unstack(t_list *lst)
{
	t_cell	*rm;

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
	return (rm);
}
