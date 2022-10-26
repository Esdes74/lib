/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:54:39 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/26 18:00:13 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

void	test_size(void)
{
	int				flag_err;
	long long int	test_val;

	flag_err = 2;
	test_val = -1;
	if (size(STRING, 0) != test_val)
		write(1, "Error : test 1 of size failed\n", 30);
	else
		flag_err--;
	if (size(LONG_LONG_UNSIGNED, 0) != sizeof(long long unsigned))
		write(1, "Error : test 2 of size failed\n", 30);
	else
		flag_err--;
	if (flag_err == 0)
		write(1, "SIZE tests are succesfull\n", 26);
	return ;
}
