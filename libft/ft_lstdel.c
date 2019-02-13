/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:22:46 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/11 18:26:28 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *next;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	next = (*alst)->next;
	ft_lstdelone(alst, del);
	if (next != NULL)
		ft_lstdel(&next, del);
}
