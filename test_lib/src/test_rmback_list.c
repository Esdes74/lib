/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rmback_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:17:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 11:31:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

static int	init_test(t_list *lst)
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
	init_list(lst);
	if (stacking_list(lst, f_test, INT, 1) == 0)
		return (0);
	if (stacking_list(lst, t_test, INT, 1) == 0)
		return (0);
	if (stacking_list(lst, th_test, INT, 1) == 0)
		return (0);
	if (stacking_list(lst, fo_test, INT, 1) == 0)
		return (0);
	return (1);
}

static void	*following_value(t_list *lst, t_cell *cel)
{
	free(cel->data_cell->data);
	free(cel->data_cell);
	free(cel);
	cel = untail_list(lst, 0);
	return (cel);
}

static int	following_test(t_list *lst, t_cell *cel)
{
	int	nbr_test;
	int	*val;

	cel = following_value(lst, cel);
	val = (int *) cel->data_cell->data;
	nbr_test = 4;
	if (*val != 4)
		write(1, "Error : test 4 of rmback_list (untail forth)\n", 45);
	else
		nbr_test--;
	if (lst->head != 0 || lst->tail != 0)
		write(1, "Error : test 5 of rmback_list (head/tail point null)\n", 53);
	else
		nbr_test--;
	if (lst->len != 0)
		write(1, "Error : test 6 of rmback_list (len calcul)\n", 43);
	else
		nbr_test--;
	cel = following_value(lst, cel);
	if (cel != 0 || lst->len != 0 || lst->head != 0 || lst->tail != 0)
		write(1, "Error : test 7 of rmback_list (too much unstack)\n", 49);
	else
		nbr_test--;
	return (nbr_test);
}

static int	first_test_rmback(t_list *lst)
{
	int		nbr_test;
	int		*val;
	t_cell	*cel;

	nbr_test = 3;
	cel = untail_list(lst, 1);
	val = (int *) cel->data_cell->data;
	if (*val != 1 || lst->tail->prev != lst->head->next || lst->tail->next != 0)
		write(1, "Error : test 1 of rmback_list (untail first)\n", 45);
	else
		nbr_test--;
	cel = following_value(lst, cel);
	val = (int *) cel->data_cell->data;
	if (*val != 2 || lst->len != 2 || lst->tail->prev != lst->head)
		write(1, "Error : test 2 of rmback_list (untail second)\n", 46);
	else
		nbr_test--;
	cel = following_value(lst, cel);
	val = (int *) cel->data_cell->data;
	if (*val != 3 || lst->tail->prev != 0 || lst->tail->next != 0)
		write(1, "Error : test 3 of rmback_list (untail third)\n", 45);
	else
		nbr_test--;
	nbr_test += following_test(lst, cel);
	return (nbr_test);
}

void	test_rmback_list(void)
{
	t_list	*l_test;
	int		nbr_err;

	nbr_err = 0;
	l_test = (t_list *) malloc(sizeof(t_list));
	init_test(l_test);
	nbr_err += first_test_rmback(l_test);
	if (nbr_err == 0)
		write(1, "RMBACK_LIST tests are succesfull\n", 33);
	free(l_test);
	return ;
}
