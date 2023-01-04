/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:56:43 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 20:24:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINT_H
# define LIB_PRINT_H
# include <unistd.h>
# include <stdarg.h>

// Write caractere c in descriptor file fd
size_t	ft_putchar_fd(char c, int fd);

// Write string s in descriptor file fd
size_t	ft_putstr_fd(char *s, int fd);

// Write string s in descriptor file fd with end line
size_t	ft_putendl_fd(char *s, int fd);

// Write integer n in descriptor file fd with end line
size_t	ft_putnbr_fd(int n, int fd);

// Printf by 42
int		ft_printf(const char *str, ...);

// Convert integer from base 10 to base 16
void	conv_ten_to_hex(int nbr, char dep, int *res);

// Convert integer from base 10 to base 16 and print at adress format
void	print_adress(long long int nbr, char dep, int *res, int mod);
#endif
