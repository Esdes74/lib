/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmback_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:14:29 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 11:49:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_cell	*rmback_list(t_list *lst, int debug)
{
	t_cell	*rm;

	if (lst->type_lst != LIST || lst->len == 0)
	{
		if (debug == 1 && lst->type_lst != LIST)
		{
			write(1, "ERROR : fct rmback_list : Utilisation of fct list", 49);
			write(1, " on non list data structure\n", 28);
		}
		return (0);
	}
	rm = lst->head;
	if (lst->len > 1)
	{
		while (rm->next->next != 0)
			rm = rm->next;
		lst->tail = rm;
		rm = rm->next;
	}
	lst->tail->next = 0;
	if (lst->len == 1)
		return (lst->head = 0, lst->tail = 0, lst->len--, rm);
	lst->len--;
	return (rm);
}
