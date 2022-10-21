/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:42:09 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/21 11:08:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

int	test_init_int(void)
{
	int		test;
	int		*def;
	int		nbr_test;
	t_data	*cell;

	nbr_test = 3;
	cell = (t_data *) malloc(sizeof(t_data));
	test = 10;
	init_data(&test, INT, FALSE, cell);
	if (cell->type_data != INT || cell->allowed != FALSE)
		write(1, "Error : test 1 of init_data failed (test_init_int)\n", 51);
	else
		nbr_test--;
	def = (int *) cell->data;
	if (*def != 10)
		write(1, "Error : test 2 of init_data failed (test_init_data)\n", 52);
	else
		nbr_test--;
	test = 15;
	if (*def != 15)
		write(1, "Error : test 3 of init_data failed (test_init_data)\n", 52);
	else
		nbr_test--;
	free(cell);
	return (nbr_test);
}

int	test_init_allowed_int(void)
{
	return (0);
}

void	test_init_data(void)
{
	int	nbr_err;

	nbr_err = 0;
	nbr_err += test_init_int();
	nbr_err += test_init_allowed_int();
	if (nbr_err == 0)
		write(1, "INIT_DATA tests are successfull\n", 32);
	return ;
}
