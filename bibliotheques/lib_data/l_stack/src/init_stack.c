/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:51:00 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/11 14:19:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

t_list	*init_stack(t_type t, t_list *stk)
{
	stk = (t_list *) malloc(sizeof(t_list));
	stk->len = 0;
	stk->type_lst = t;
	stk->head = 0;
	stk->tail = 0;
	return (stk);
}
