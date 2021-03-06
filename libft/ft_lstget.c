/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:13:03 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/11 19:19:46 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, const size_t index)
{
	size_t i;

	i = 0;
	while (lst && i < index)
	{
		++i;
		lst = lst->next;
	}
	return (lst);
}
