/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:41:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/16 13:03:31 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "width.h"

char	*ft_width(const char *str, int *str_index, char filler)
{
	int		i;
	int		len;
	char	*res;
	
	len = ft_atoi(&str[*str_index]);
	while (str[*str_index] >= '0' && str[*str_index] <= '9')
		(*str_index)++;
	if ((res = malloc((len + 1) * sizeof(*res))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = filler;
	return (res);
}
