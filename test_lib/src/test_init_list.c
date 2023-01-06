/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:20:53 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/06 19:33:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

void	test_init_list(void)
{
	t_list	lst;
	int		nbr_test;

	nbr_test = 1;
	init_list(&lst);
	if (lst.len != 0 || lst.type_lst != LIST)
		write(1, "Error : test 1 of init_list failed (len/type init)\n", 51);
	else if (lst.head != NULL || lst.tail != NULL)
		write(1, "Error : test 2 of init_list failed (head/tail init)\n", 52);
	else
		nbr_test--;
	if (nbr_test == 0)
		write(1, "INIT_LIST tests are succesfull\n", 31);
	return ;
}
