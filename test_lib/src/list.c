/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:26:26 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/14 17:47:15 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

void	test_init_list()
{
	t_list *list;

	list = 0;
	init_list(list);
	free(list->head);
	free(list);
}

void	test_calc_ind(int len, int ind)
{
	(void) len;
	(void) ind;

	return ;
}
