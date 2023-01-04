/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ten_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:03:08 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 20:27:15 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_print.h"

void	print_adress(long long int nbr, char dep, int *res, int mod)
{
	long long unsigned int	u_nbr;

	if (mod == 1)
		(*res) += ft_putstr_fd("0x", 1);
	u_nbr = nbr;
	if (u_nbr > 0)
	{
		print_adress(u_nbr / 16, dep, res, 0);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, 1);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, 1);
	}
}

void	conv_ten_to_hex(int nbr, char dep, int *res)
{
	unsigned int	u_nbr;

	u_nbr = nbr;
	if (u_nbr > 0)
	{
		conv_ten_to_hex(u_nbr / 16, dep, res);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, 1);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, 1);
	}
}
