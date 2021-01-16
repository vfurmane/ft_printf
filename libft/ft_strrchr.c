/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:28:36 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/05 14:49:20 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int chr)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (str[i])
	{
		if (str[i] == (unsigned char)chr)
			ptr = &str[i];
		i++;
	}
	if ((unsigned char)chr == '\0')
		return (&str[i]);
	return (ptr);
}
