/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:28 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 16:02:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

int	is_list(t_type t)
{
	return (t == LIST || t == STACK || t == QUEUE || t == DICO \
			|| t == LIST_IND);
}