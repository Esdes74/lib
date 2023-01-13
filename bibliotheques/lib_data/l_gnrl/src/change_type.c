/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:45:00 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/13 13:58:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	change_type(t_list *lst, t_type type, int debug)
{
	if (type == LIST || type == STACK || type == DICO || type == QUEUE)
	{
		if (lst->type_lst == LIST || lst->type_lst == STACK || \
				lst->type_lst == QUEUE || lst->type_lst == DICO)
			lst->type_lst = type;
		else
			if (debug == 1)
			{
				ft_printf("Error : fct change_type : Not good type of list to");
				ft_printf(" change");
			}
	}
	else
		if (debug == 1)
			ft_printf("Error : fct change_type : Not good type to change");
}
