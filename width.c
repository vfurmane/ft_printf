/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:41:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/20 16:47:48 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "width.h"

char	*ft_width(const char *str, int *str_index, int len, char filler)
{
	int		i;
	char	*res;

	if (str[*str_index] == '*')
		(*str_index)++;
	else
	{
		len = ft_atoi(&str[*str_index]);
		while (str[*str_index] >= '0' && str[*str_index] <= '9')
			(*str_index)++;
	}
	if (len < 0)
		len = -len;
	if ((res = malloc((len + 1) * sizeof(*res))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = filler;
	res[i] = '\0';
	return (res);
}
