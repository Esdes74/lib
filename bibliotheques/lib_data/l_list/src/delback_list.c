/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delback_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:55:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/07 21:14:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

void	delback_list(t_list *lst, t_bool allow, int debug)
{
	t_cell	*u_data;

	if (lst->type_lst == LIST && lst->len != 0)
	{
		u_data = rmback_list(lst, debug);
		if (u_data->data_cell->allowed == TRUE || allow == TRUE)
			free(u_data->data_cell->data);
		free(u_data->data_cell);
		free(u_data);
	}
	else
		if (debug == 1 && lst->type_lst != LIST)
			write(1, "ERROR : fct delback_list : Utilisation of fct stack on \
					non list data structure\n", 80);
}
