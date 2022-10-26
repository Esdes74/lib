/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:51:00 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/26 17:07:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

t_list	*init_stack(t_list *stk)
{
	stk->len = 0;
	stk->type_lst = STACK;
	stk->head = 0;
	stk->tail = 0;
	return (stk);
}
