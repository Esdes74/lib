/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:39:11 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/20 18:23:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

void	test_stack(void)
{
	test_init_stack();
	test_stacking();
	test_stacking_val();
	test_unstack();
	test_rmstack();
}
