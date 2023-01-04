/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:38:58 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 11:06:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_data	*init_data(void *d, t_type t, t_bool allow, t_data *cell)
{
	cell->allowed = allow;
	cell->type_data = t;
	cell->data = d;
	return (cell);
}
