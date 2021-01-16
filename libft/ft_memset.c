/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:30:38 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 18:12:12 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int chr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char*)str)[i] = chr;
		i++;
	}
	return (str);
}
