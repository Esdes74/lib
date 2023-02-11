/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:15:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/11 14:17:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	clear_cell(t_cell *cell, void (*f)(void *))
{
	if (cell->next != 0)
		cell->next->prev = cell->prev;
	if (cell->prev != 0)
		cell->prev->next = cell->next;
	f(cell->data_cell->data);
	free(cell->data_cell);
	free(cell);
}
