/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:40:40 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/20 17:07:10 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

t_data	*init_data(void *d, t_type t, t_bool allow, t_data *cell)
{
	cell->allowed = allow;
	cell->type_data = t;
	cell->data = d;
	return (cell);
}
