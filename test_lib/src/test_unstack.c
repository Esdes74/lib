/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:38:49 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/26 16:33:33 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"
#include <stdio.h>

void	init_test_unstack(t_list lst)
{
	int	*p_test;
	int	f_test;
	int	t_test;
	int	th_test;
	int	fo_test;

	f_test = 1;
	t_test = 2;
	th_test = 3;
	fo_test = 4;
	init_stack(&lst);
	p_test = &f_test;
	if (stacking(&lst, p_test, INT, 1) == 0)
		write(1, "PB\n", 3);
	p_test = &t_test;
	if (stacking(&lst, p_test, INT, 1) == 0)
		write(1, "PB\n", 3);
	p_test = &th_test;
	if (stacking(&lst, p_test, INT, 1) == 0)
		write(1, "PB\n", 3);
	p_test = &fo_test;
	if (stacking(&lst, p_test, INT, 1) == 0)
		write(1, "PB\n", 3);
}

void	*following_value(t_list lst, t_cell *cel)
{
	free(cel->data_cell);
	free(cel);
	cel = unstack(&lst, 0);
	return (cel->data_cell->data);
}

int	following_test(t_list lst, t_cell *cel)
{
	int	nbr_test;
	int	*val;

	val = (int *) following_value(lst, cel);
	nbr_test = 2;
	if (*val != 1)
		write(1, "Error : test 4 of unstack (unstack forth)\n", 42);
	else
		nbr_test--;
	if (lst.head != 0 || lst.tail != 0)
		write(1, "Error : test 5 of unstack (head/tail point null)\n", 49);
	else
		nbr_test--;
	free(cel->data_cell);
	free(cel);
	return (nbr_test);
}

int	first_test_unstack(t_list lst)
{
	int		nbr_test;
	int		*val;
	t_cell	*cel;

	nbr_test = 3;
	cel = unstack(&lst, 1);
	printf("cel = %p\n", cel);
	write(1, "TEST\n", 5);
	val = (int *) cel->data_cell->data;
	if (*val != 4)
		write(1, "Error : test 1 of unstack (unstack first)\n", 42);
	else
		nbr_test--;
	val = (int *) following_value(lst, cel);
	if (*val != 3)
		write(1, "Error : test 2 of unstack (unstack second)\n", 43);
	else
		nbr_test--;
	val = (int *) following_value(lst, cel);
	if (*val != 2)
		write(1, "Error : test 3 of unstack (unstack third)\n", 42);
	else
		nbr_test--;
	nbr_test += following_test(lst, cel);
	return (nbr_test);
}

void	test_unstack(void)
{
	t_list	l_test;
	int		nbr_err;

	nbr_err = 0;
	init_test_unstack(l_test);
	nbr_err += first_test_unstack(l_test);
	if (nbr_err == 0)
		write(1, "UNSTACK tests are succesfull\n", 29);
	return ;
}
