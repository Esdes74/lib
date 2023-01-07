/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oracle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:03:18 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/07 21:09:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORACLE_H
# define ORACLE_H
# include <unistd.h>
# include <stdlib.h>
# include "../bibliotheques/libft.h"

// ################# LIST ####################

void	test_list(void);

void	test_init_list(void);

void	test_stacking_list(void);

void	test_unstack_list(void);

void	test_rmstack_list(void);

void	test_addback_list(void);

void	test_rmback_list(void);

void	test_delback_list(void);

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
