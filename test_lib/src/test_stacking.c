/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stacking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:40:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 12:36:58 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

static int	test_stacked_val(t_list *lst, int ind)
{
	int	nbr_test;
	int	*val;
	int	*sec_val;

	if (ind == 0)
	{
		val = (int *) lst->head->data_cell->data;
		nbr_test = 1;
		if (*val != 15)
			write(1, "Error : test 0.6 of stacking failed (data stack)\n", 50);
		else
			nbr_test--;
	}
	else
	{
		val = (int *) lst->head->data_cell->data;
		sec_val = (int *) lst->tail->data_cell->data;
		nbr_test = 1;
		if (*val != 45)
			write(1, "Error : test 1.6 of stacking failed (data stack)\n", 50);
		else if (*sec_val != 15)
			write(1, "Error : test 1.7 of stacking failed (data stack)\n", 50);
		else
			nbr_test--;
	}
	return (nbr_test);
}

static int	first_test_stacking(t_list lst)
{
	int	nbr_test;

	nbr_test = 6;
	if (lst.head != lst.tail || lst.head == 0 || lst.tail == 0)
		write(1, "Error : test 0.1 of stacking failed (head/tail init)\n", 53);
	else
		nbr_test--;
	if (lst.len != 1)
		write(1, "Error : test 0.2 of stacking failed (len init)\n", 47);
	else
		nbr_test--;
	if (lst.head->next != 0 || lst.tail->next != 0)
		write(1, "Error : test 0.3 of stacking failed (following cell)\n", 53);
	else
		nbr_test--;
	if (lst.head->data_cell->type_data != INT)
		write(1, "Error : test 0.4 of stacking failed (type_data init)\n", 53);
	else
		nbr_test--;
	if (lst.head->data_cell->allowed != FALSE)
		write(1, "Error : test 0.5 of stacking failed (allowed init)\n", 51);
	else
		nbr_test--;
	if (lst.head->prev != 0 || lst.tail->prev != 0)
		write(1, "Error : test 0.6 of stacking failed (previous cell)\n", 52);
	else
		nbr_test--;
	nbr_test += test_stacked_val(&lst, 0);
	return (nbr_test);
}

static int	second_test_stacking(t_list lst)
{
	int	nbr_test;

	nbr_test = 6;
	if (lst.head == lst.tail || lst.head == 0 || lst.tail == 0 || lst.len != 2)
		write(1, "Error : test 1.1 of stacking failed (head/tail init)\n", 53);
	else
		nbr_test--;
	if (lst.head->next == 0 || lst.tail->next != 0)
		write(1, "Error : test 1.2 of stacking failed (following cell)\n", 53);
	else
		nbr_test--;
	if (lst.head->next != lst.tail || lst.tail->next != 0)
		write(1, "Error : test 1.3 of stacking failed (following head)\n", 53);
	else
		nbr_test--;
	if (lst.tail->data_cell->type_data != INT)
		write(1, "Error : test 1.4 of stacking failed (type_data init)\n", 53);
	else
		nbr_test--;
	if (lst.tail->data_cell->allowed != FALSE)
		write(1, "Error : test 1.5 of stacking failed (allowed init)\n", 51);
	else
		nbr_test--;
	if (lst.head->prev != 0 || lst.tail->prev != lst.head)
		write(1, "Error : test 1.6 of stacking failed (previous cell)\n", 52);
	else
		nbr_test--;
	nbr_test += test_stacked_val(&lst, 1);
	return (nbr_test);
}

void	test_stacking(void)
{
	t_list	*test;
	int		nbr_err;
	int		*point_test;
	int		val_test;
	int		sec_val_test;

	test = (t_list *) malloc(sizeof(t_list));
	if (test == 0)
		return ;
	point_test = &val_test;
	val_test = 15;
	nbr_err = 0;
	init_stack(test);
	stacking(test, point_test, INT, 0);
	nbr_err += first_test_stacking(*test);
	point_test = &sec_val_test;
	sec_val_test = 45;
	stacking(test, point_test, INT, 0);
	nbr_err += second_test_stacking(*test);
	if (nbr_err == 0)
		write(1, "STACKING tests are succesfull\n", 30);
	annihilation(test, none, DEBUG);
	return ;
}
