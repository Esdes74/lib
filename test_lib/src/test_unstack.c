/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:38:49 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 20:48:48 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"
#include <stdio.h>

int	init_test_unstack(t_list *lst)
{
	int	*f_test;
	int	*t_test;
	int	*th_test;
	int	*fo_test;

	f_test = (int *) malloc(sizeof(int));
	t_test = (int *) malloc(sizeof(int));
	th_test = (int *) malloc(sizeof(int));
	fo_test = (int *) malloc(sizeof(int));
	*f_test = 1;
	*t_test = 2;
	*th_test = 3;
	*fo_test = 4;
	init_stack(lst);
	if (stacking(lst, f_test, INT, 1) == 0)
		return (0);
	if (stacking(lst, t_test, INT, 1) == 0)
		return (0);
	if (stacking(lst, th_test, INT, 1) == 0)
		return (0);
	if (stacking(lst, fo_test, INT, 1) == 0)
		return (0);
	return (1);
}

void	*following_value(t_list *lst, t_cell *cel)
{
	free(cel->data_cell->data);
	free(cel->data_cell);
	free(cel);
	cel = unstack(lst, 0);
	return (cel);
}

int	following_test(t_list *lst, t_cell *cel)
{
	int	nbr_test;
	int	*val;

	cel = following_value(lst, cel);
	val = (int *) cel->data_cell->data;
	nbr_test = 4;
	if (*val != 1)
		write(1, "Error : test 4 of unstack (unstack forth)\n", 42);
	else
		nbr_test--;
	if (lst->head != 0 || lst->tail != 0)
		write(1, "Error : test 5 of unstack (head/tail point null)\n", 49);
	else
		nbr_test--;
	if (lst->len != 0)
		write(1, "Error : test 6 of unstack (len calcul)\n", 39);
	else
		nbr_test--;
	cel = following_value(lst, cel);
	if (cel != 0 || lst->len != 0 || lst->head != 0 || lst->tail != 0)
		write(1, "Error : test 7 of unstack (too much unstack)\n", 45);
	else
		nbr_test--;
	return (nbr_test);
}

int	first_test_unstack(t_list *lst)
{
	int		nbr_test;
	int		*val;
	t_cell	*cel;

	nbr_test = 3;
	cel = unstack(lst, 1);
	val = (int *) cel->data_cell->data;
	if (*val != 4 || lst->tail->prev != lst->head->next)
		write(1, "Error : test 1 of unstack (unstack first)\n", 42);
	else
		nbr_test--;
	cel = following_value(lst, cel);
	val = (int *) cel->data_cell->data;
	if (*val != 3 || lst->len != 2 || lst->tail->prev != lst->head)
		write(1, "Error : test 2 of unstack (unstack second)\n", 43);
	else
		nbr_test--;
	cel = following_value(lst, cel);
	val = (int *) cel->data_cell->data;
	if (*val != 2 || lst->tail->prev != 0)
		write(1, "Error : test 3 of unstack (unstack third)\n", 42);
	else
		nbr_test--;
	nbr_test += following_test(lst, cel);
	return (nbr_test);
}

void	test_unstack(void)
{
	t_list	*l_test;
	int		nbr_err;

	nbr_err = 0;
	l_test = (t_list *) malloc(sizeof(t_list));
	init_test_unstack(l_test);
	nbr_err += first_test_unstack(l_test);
	if (nbr_err == 0)
		write(1, "UNSTACK tests are succesfull\n", 29);
	free(l_test);
	return ;
}
