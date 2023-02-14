/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:51:00 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 16:48:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

t_list	*init_stack(t_list *stk)
{
	if (lst == 0)
		return (write(1, "Error : fct init_stack : lst null\n", 34), 0);
	stk->len = 0;
	stk->type_lst = STACK;
	stk->head = 0;
	stk->tail = 0;
	return (stk);
}
