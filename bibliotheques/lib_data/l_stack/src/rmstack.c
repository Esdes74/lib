/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:53:14 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/14 16:01:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

void	rmstack(t_list *lst, int debug)
{
	t_cell	*u_data;

	if (lst->type_lst == STACK)
	{
		u_data = unstack(lst, debug);
		if (u_data->data_cell->allowed == TRUE)
			free(u_data->data_cell->data);
		free(u_data->data_cell);
		free(u_data);
	}
	else
		if (debug == 1)
			write(1, "ERROR : fct rmstack : Utilisation of fct stack on non \
					stack data structure\n", 76);
}
