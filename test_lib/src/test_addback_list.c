/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_addback_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:33:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 12:01:38 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

static int	test_stacked_val(t_list *lst, int ind)
{
	int	nbr_test;

	if (ind == 0)
	{
		nbr_test = 1;
		if (*((int *)lst->head->data_cell->data) != 15)
			write(1, "Error : test 0.7 of stacking_list failed \
					(data stack)\n", 55);
		else
			nbr_test--;
	}
	else
	{
		nbr_test = 2;
		if (*((int *)lst->head->data_cell->data) != 15)
			write(1, "Error : test 1.7 of stack_l failed (data stack)\n", 48);
		else
			nbr_test--;
		if (*((int *)lst->tail->data_cell->data) != 45)
			write(1, "Error : test 1.8 of stack_l failed (data stack)\n", 48);
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
		write(1, "Error : test 0.1 of stack_l failed (head/tail init)\n", 52);
	else
		nbr_test--;
	if (lst.len != 1)
		write(1, "Error : test 0.2 of stack_l failed (len init)\n", 46);
	else
		nbr_test--;
	if (lst.head->next != 0 || lst.tail->next != 0)
		write(1, "Error : test 0.3 of stack_l failed (following cell)\n", 52);
	else
		nbr_test--;
	if (lst.head->data_cell->type_data != INT)
		write(1, "Error : test 0.4 of stack_l failed (type_data init)\n", 52);
	else
		nbr_test--;
	if (lst.head->data_cell->allowed != FALSE)
		write(1, "Error : test 0.5 of stack_l failed (allowed init)\n", 50);
	else
		nbr_test--;
	if (lst.head->prev != 0 || lst.tail->prev != 0)
		write(1, "Error : test 0.6 of stack_l failed (previous cell)\n", 51);
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
		write(1, "Error : test 1.1 of stack_l failed (head/tail init)\n", 52);
	else
		nbr_test--;
	if (lst.head->next == 0 || lst.tail->next != 0)
		write(1, "Error : test 1.2 of stack_l failed (following cell)\n", 52);
	else
		nbr_test--;
	if (lst.head->next != lst.tail || lst.tail->next != 0)
		write(1, "Error : test 1.3 of stack_l failed (following head)\n", 52);
	else
		nbr_test--;
	if (lst.tail->data_cell->type_data != INT)
		write(1, "Error : test 1.4 of stack_l failed (type_data init)\n", 52);
	else
		nbr_test--;
	if (lst.tail->data_cell->allowed != FALSE)
		write(1, "Error : test 1.5 of stack_l failed (allowed init)\n", 50);
	else
		nbr_test--;
	if (lst.head->prev != 0 || lst.tail->prev != lst.head)
		write(1, "Error : test 1.6 of stack_l failed (previous cell)\n", 51);
	else
		nbr_test--;
	nbr_test += test_stacked_val(&lst, 1);
	return (nbr_test);
}

/* static void	annihilation_test_stacking(t_list *lst) */
/* { */
/* 	if (lst->head != 0) */
/* 	{ */
/* 		free(lst->head->data_cell); */
/* 		lst->tail = lst->head->next; */
/* 		free(lst->head); */
/* 		lst->head = lst->tail; */
/* 		annihilation_test_stacking(lst); */
/* 	} */
/* } */

void	test_addback_list(void)
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
	init_list(test);
	tailing_list(test, point_test, INT, 0);
	nbr_err += first_test_stacking(*test);
	point_test = &sec_val_test;
	sec_val_test = 45;
	tailing_list(test, point_test, INT, 0);
	nbr_err += second_test_stacking(*test);
	if (nbr_err == 0)
		write(1, "ADDBACK_LIST tests are succesfull\n", 34);
	annihilation(test, none);
	return ;
}
