/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:23:55 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/11 18:25:16 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	void *next;

	if (lst == NULL || f == NULL)
		return ;
	next = lst->next;
	f(lst);
	if (next != NULL)
		ft_lstiter(next, f);
}
