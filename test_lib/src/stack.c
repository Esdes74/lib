/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:39:11 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/27 16:33:23 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

int	test_stack(void)
{
	test_init_stack();
	test_stacking();
	test_unstack();
	if (test_rmstack() == 0)
		return (0);
	test_stacking_val();
	return (1);
}
