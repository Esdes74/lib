/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:41:35 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/25 13:41:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

void	test_init_stack(void)
{
	t_list	stacked;
	int		nbr_test;

	nbr_test = 1;
	init_stack(&stacked);
	if (stacked.len != 0 || stacked.type_lst != STACK)
		write(1, "Error : test 1 of init_stack failed (len/type init)\n", 52);
	else if (stacked.head != NULL || stacked.tail != NULL)
		write(1, "Error : test 2 of init_stack failed (head/tail init)\n", 53);
	else
		nbr_test--;
	if (nb_test == 0)
		write(1, "INIT_STACK tests are succesfull\n", 32);
	return ;
}
