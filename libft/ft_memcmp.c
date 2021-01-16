/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:14:39 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 10:39:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)str1)[i] != ((unsigned char*)str2)[i])
			return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
		i++;
	}
	return (0);
}
