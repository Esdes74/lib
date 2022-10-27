/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oracle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:03:18 by eslamber          #+#    #+#             */
/*   Updated: 2022/10/27 16:31:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORACLE_H
# define ORACLE_H
# include <unistd.h>
# include <stdlib.h>
# include "../bibliotheques/libft.h"

void	test_list(void);

// ################# STACK ###################
int		test_stack(void);

void	test_init_stack(void);

void	test_stacking(void);

void	test_stacking_val(void);

void	test_unstack(void);

int		test_rmstack(void);

// ################# GNRL ####################
int		test_gnrl(void);

int		test_init_data(void);

void	test_size(void);

#endif
