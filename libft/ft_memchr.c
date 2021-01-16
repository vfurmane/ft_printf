/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:14:39 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 10:38:24 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)str)[i] == (unsigned char)chr)
			return (&((unsigned char*)str)[i]);
		i++;
	}
	return (NULL);
}
