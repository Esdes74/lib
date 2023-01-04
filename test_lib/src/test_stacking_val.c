/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stacking_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:37:09 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 10:41:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

int	init_test_stacking_val(t_list *lst)
{
	int	*test;
	int	f_test;
	int	t_test;
	int	th_test;
	int	fo_test;

	f_test = 1;
	t_test = 2;
	th_test = 3;
	fo_test = 4;
	init_stack(lst);
	test = &f_test;
	if (stacking_val(lst, test, INT, 1) == 0)
		return (0);
	test = &t_test;
	if (stacking_val(lst, test, INT, 1) == 0)
		return (0);
	test = &th_test;
	if (stacking_val(lst, test, INT, 1) == 0)
		return (0);
	test = &fo_test;
	if (stacking_val(lst, test, INT, 1) == 0)
		return (0);
	return (1);
}

void	*following_values(t_list *lst, t_cell *cel)
{
	free(cel->data_cell->data);
	free(cel->data_cell);
	free(cel);
	cel = unstack(lst, 0);
	return (cel);
}

int	following_tests(t_list *lst, t_cell *cel)
{
	int	nbr_test;
	int	*val;

	cel = following_values(lst, cel);
	val = (int *) cel->data_cell->data;
	nbr_test = 3;
	if (*val != 1)
		write(1, "Error : test 4 of unstack_val (unstack forth)\n", 46);
	else
		nbr_test--;
	if (lst->head != 0 || lst->tail != 0)
		write(1, "Error : test 5 of unstack_val (head/tail point null)\n", 53);
	else
		nbr_test--;
	if (lst->len != 0)
		write(1, "Error : test 6 of unstack_val (len calcul)\n", 43);
	else
		nbr_test--;
	free(cel->data_cell->data);
	free(cel->data_cell);
	free(cel);
	return (nbr_test);
}

int	first_test_stacking_val(t_list *lst)
{
	int		nbr_test;
	int		*val;
	t_cell	*cel;

	nbr_test = 3;
	cel = unstack(lst, 1);
	val = (int *) cel->data_cell->data;
	if (*val != 4)
		write(1, "Error : test 1 of unstack_val (unstack first)\n", 46);
	else
		nbr_test--;
	cel = following_values(lst, cel);
	val = (int *) cel->data_cell->data;
	if (*val != 3 && lst->len != 3)
		write(1, "Error : test 2 of unstack_val (unstack second)\n", 47);
	else
		nbr_test--;
	cel = following_values(lst, cel);
	val = (int *) cel->data_cell->data;
	if (*val != 2)
		write(1, "Error : test 3 of unstack_val (unstack third)\n", 46);
	else
		nbr_test--;
	nbr_test += following_tests(lst, cel);
	return (nbr_test);
}

void	test_stacking_val(void)
{
	t_list	*l_test;
	int		nbr_err;

	nbr_err = 0;
	l_test = (t_list *) malloc(sizeof(t_list));
	init_test_stacking_val(l_test);
	nbr_err += first_test_stacking_val(l_test);
	if (nbr_err == 0)
		write(1, "UNSTACK_VAL tests are succesfull\n", 33);
	free(l_test);
	return ;
}
