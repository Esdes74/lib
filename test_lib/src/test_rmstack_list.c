/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rmstack_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:08:08 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/07 20:26:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

static int	init_test_rmstack_list(t_list *lst)
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
	init_list(lst);
	if (stacking_list(lst, f_test, INT, 0) == 0)
		return (1);
	if (stacking_list(lst, s_test, INT, 0) == 0)
		return (1);
	if (stacking_list(lst, t_test, INT, 0) == 0)
		return (1);
	if (stacking_list(lst, fo_test, INT, 0) == 0)
		return (1);
	return (0);
}

static int	test_lst(t_list *lst)
{
	t_cell		*cell;
	int			i;
	static int	nbr_t;

	i = 1;
	cell = lst->tail;
	while (cell != 0)
	{
		if (*((int *)cell->data_cell->data) != i)
		{
			ft_printf("Error : test %d of rmstack_list (values test)\n", nbr_t);
			nbr_t++;
			return (1);
		}
		i++;
		cell = cell->prev;
	}
	nbr_t++;
	return (0);
}

void	test_rmstack_list(void)
{
	t_list	*lst_test;
	int		nbr_err;

	lst_test = (t_list *) malloc(sizeof(t_list));
	if (lst_test == 0)
		return ;
	nbr_err = 0;
	nbr_err += init_test_rmstack_list(lst_test);
	if (nbr_err == 1)
		return ;
	rmstack_list(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack_list(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack_list(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack_list(lst_test, TRUE, 0);
	test_lst(lst_test);
	rmstack_list(lst_test, TRUE, 0);
	if (nbr_err == 0)
		write(1, "RMSTACK_LIST tests are succesfull\n", 34);
	free(lst_test);
	return ;
}
