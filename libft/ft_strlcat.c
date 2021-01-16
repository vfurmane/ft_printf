/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:46:47 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 18:12:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	int		i;
	size_t	src_len;
	size_t	dest_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	if (dest_size == 0)
		return (src_len);
	if ((int)dest_size < 0)
		dest_size = src_len + 1;
	if (dest_len > dest_size)
		return (src_len + dest_size);
	i = 0;
	while (src[i] && i < (int)(dest_size - dest_len - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
