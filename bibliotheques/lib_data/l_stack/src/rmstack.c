/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:53:14 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/13 18:25:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

void	rmstack(t_list *lst, int debug)
{
	if (lst->type_lst == STACK)
		free(unstack(lst, debug));
	else
		if (debug == 1)
			write(1, "ERROR : fct rmstack : Utilisation of fct stack on non \
					stack data structure\n", 76);
}
