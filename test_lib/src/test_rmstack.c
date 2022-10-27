/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rmstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:38:02 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/27 16:50:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

int	init_test_rmstack(t_list *lst)
{
	(void) lst;
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
	if (nbr_err == 0)
		write(1, "RMSTACK tests are succesfull\n", 29);
	free(lst_test);
	return (1);
}
