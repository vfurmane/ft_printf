/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:12:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 18:12:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	int		i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dest_size == 0)
		return (src_len);
	if ((int)dest_size < 0)
		dest_size = src_len + 1;
	i = 0;
	while (src[i] && i < (int)dest_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
