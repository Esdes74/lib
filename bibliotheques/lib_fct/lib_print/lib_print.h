/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:56:43 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:13:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINT_H
# define LIB_PRINT_H
# include <unistd.h>

// Write caractere c in descriptor file fd
void	ft_putchar_fd(char c, int fd);

// Write string s in descriptor file fd
void	ft_putstr_fd(char *s, int fd);

// Write string s in descriptor file fd with end line
void	ft_putendl_fd(char *s, int fd);

// Write integer n in descriptor file fd with end line
void	ft_putnbr_fd(int n, int fd);
#endif
