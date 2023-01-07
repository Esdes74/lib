/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:26:26 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/07 15:15:46 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../oracle.h"

void	test_list(void)
{
	test_init_list();
	test_stacking_list();
	test_unstack_list();
	test_rmback_list();
}
