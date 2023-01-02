/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:55:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/02 18:14:21 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_list	*init_list(t_list *lst)
{
	lst->len = 0;
	lst->type_lst = LIST;
	lst->head = 0;
	lst->tail = 0;
	return (lst);
}
