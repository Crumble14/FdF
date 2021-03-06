/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:12:12 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 16:25:53 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arrlen(void **arr)
{
	size_t len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		++len;
	return (len);
}
