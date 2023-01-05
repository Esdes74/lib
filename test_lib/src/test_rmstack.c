/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rmstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:38:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/05 20:47:41 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

static int	init_test_rmstack(t_list *lst)
{
	int	*f_test;
	int	*s_test;
	int	*t_test;
	int	*fo_test;

	f_test = (int *) malloc(sizeof(int));
	s_test = (int *) malloc(sizeof(int));
	t_test = (int *) malloc(sizeof(int));
	fo_test = (int *) malloc(sizeof(int));
	*f_test = 1;
	*s_test = 2;
	*t_test = 3;
	*fo_test = 4;
	init_stack(lst);
	if (stacking(lst, f_test, INT, 0) == 0)
		return (1);
	if (stacking(lst, s_test, INT, 0) == 0)
		return (1);
	if (stacking(lst, t_test, INT, 0) == 0)
		return (1);
	if (stacking(lst, fo_test, INT, 0) == 0)
		return (1);
	return (0);
}

static int	test_lst(t_list *lst)
{
	t_cell	*cell;
	int		i;

	i = 1;
	cell = lst->tail;
	while (cell != 0)
	{
		if (*((int *)cell->data_cell->data) != i)
		{
			ft_printf("Error : test %d of rmstack (values test)\n", i);
			return (1);
		}
		i++;
		cell = cell->prev;
	}
	return (0);
}

int	test_rmstack(void)
{
	t_list	*lst_test;
	int		nbr_err;

	lst_test = (t_list *) malloc(sizeof(t_list));
	if (lst_test == 0)
		return 0;
	nbr_err = 0;
	nbr_err += init_test_rmstack(lst_test);
	if (nbr_err == 1)
		return (0);
	rmstack(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack(lst_test, TRUE, 0);
	if (nbr_err == 0)
		write(1, "RMSTACK tests are succesfull\n", 29);
	free(lst_test);
	return (1);
}
