/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:31:44 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/14 15:18:26 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	following_debugger(t_type t)
{		
	if (t == LONG_LONG_UNSIGNED)
		write(1, "LONG_LONG_UNSIGNED\n", 19);
	if (t == LIST)
		write(1, "LIST\n", 5);
	if (t == LIST_IND)
		write(1, "LIST_IND\n", 9);
	if (t == STACK)
		write(1, "STACK\n", 6);
	if (t == QUEUE)
		write(1, "QUEUE\n", 6);
	if (t == DICO)
		write(1, "DICO\n", 5);
	if (t == TREE)
		write(1, "TREE\n", 5);
	if (t == ALEA)
		write(1, "ALEA\n", 5);
}

void	debugger(int debug, t_type t, int mod)
{
	if (debug == 1)
	{
		if (mod == 0)
			write(1, "DEBUG MOD : fct size : type given : ", 36);
		else
		{
			if (t == INT)
				write(1, "INT\n", 4);
			if (t == CHAR)
				write(1, "CHAR\n", 5);
			if (t == STRING)
				write(1, "STRING\n", 7);
			if (t == DOUBLE)
				write(1, "DOUBLE\n", 7);
			if (t == LONG)
				write(1, "LONG\n", 5);
			if (t == UNSIGNED)
				write(1, "UNSIGNED\n", 9);
			if (t == LONG_LONG)
				write(1, "LONG_LONG\n", 10);
			if (t == LONG_UNSIGNED)
				write(1, "LONG_UNSIGNED\n", 14);
			following_debugger(t);
		}
	}
}

size_t	size(t_type t, int debug)
{
	debugger(debug, t, 0);
	debugger(debug, t, 1);
	if (t == INT)
		return (sizeof(int));
	else if (t == CHAR)
		return (sizeof(char));
	else if (t == DOUBLE)
		return (sizeof(double));
	else if (t == LONG)
		return (sizeof(long));
	else if (t == UNSIGNED)
		return (sizeof(unsigned));
	else if (t == LONG_LONG)
		return (sizeof(long long));
	else if (t == LONG_UNSIGNED)
		return (sizeof(long unsigned));
	else if (t == LONG_LONG_UNSIGNED)
		return (sizeof(long long unsigned));
	return (-1);
}
