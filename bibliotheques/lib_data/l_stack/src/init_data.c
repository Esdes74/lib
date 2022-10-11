/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:40:40 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/11 14:44:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

t_data	*init_data(void *d, t_type t, t_data *cell)
{
	cell = (t_data *) malloc(sizeof(t_data));
	cell->type_data = t;
	cell->data = d;
	return (cell);
}
