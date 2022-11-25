/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_simple.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:10:49 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/25 14:22:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_SIMPLE_H
# define L_SIMPLE_H
# include <stdlib.h>

typedef struct s_listft{
	void			*content;
	struct s_listft	*next;
}	t_listft;

// Creat a new cell with next = 0 and content = new_content
t_listft	*ft_lstnew(void *new_content);

// Add new in front of list pointed by lst
void		ft_lstadd_front(t_listft **lst, t_listft *new);

// Return lenght of lst
int			ft_lstsize(t_listft *lst);

// Return last cell of list
t_listft	*ft_lstlast(t_listft *lst);

// Add new at the end of list
void		ft_lstadd_back(t_listft **lst, t_listft *new);

// Remove one element of list
void		ft_lstdelone(t_listft *lst, void (*del)(void *));

// Clear all the list
void		ft_lstclear(t_listft **lst, void (*del)(void *));

// Apply f function to all contents of list
void		ft_lstiter(t_listft *lst, void (*f)(void *));

// Apply f function to all contents and creat a new list with modifications
t_listft	*ft_lstmap(t_listft *lst, void *(*f)(void *), void (*del)(void *));
#endif
