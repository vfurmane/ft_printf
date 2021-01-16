/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:14:39 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 10:37:26 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int chr, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		((char*)dest)[i] = ((char*)src)[i];
		if (((char*)src)[i] == (unsigned char)chr)
			return (&((char*)dest)[i + 1]);
		i++;
	}
	return (NULL);
}
