/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annihilation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:58:32 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 12:43:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	annihilation(t_list *lst, void (*f)(void *), int debug)
{
	t_cell	*tmp;

	if (lst == 0 || f == 0)
	{
		if (debug)
			ft_printf("ERROR : fct annihilation : One or more arguments are \
					null\n");
		return ;
	}
	if (lst->type_lst != LIST && lst->type_lst != STACK && lst->type_lst != QUEUE && lst->type_lst != DICO && lst->type_lst != LIST_IND)
	{
		if (debug)
			ft_printf("ERROR : fct annihilation : Utilisation of type list not \
					good\n");
		return ;
	}
	tmp = lst->head;
	while (tmp != 0)
	{
		tmp = tmp->next;
		f(lst->head->data_cell->data);
		free(lst->head->data_cell);
		free(lst->head);
		lst->head = tmp;
	}
	free(lst);
}
