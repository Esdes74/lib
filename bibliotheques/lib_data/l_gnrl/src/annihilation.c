/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annihilation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:15:54 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/13 18:46:30 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	annihilation(t_list *lst, void (*f)(void *))
{
	t_cell	*tmp;

	if (lst == 0 || f == 0)
	{
		ft_printf("ERROR : fct annihilation : On or more arguments are null");
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
