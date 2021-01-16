/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:49:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/16 13:01:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int	ft_flags(const char *str, int *str_index, char **res)
{
	int		minus;
	char	filler;

	minus = 0;
	filler = ' ';
	while (str[*str_index] && ft_strchr("-0", str[*str_index]) != NULL)
	{
		if (str[*str_index] == '-')
			minus = 1;
		else if (str[*str_index] == '0' && minus == 0)
			filler = '0';
		(*str_index)++;
	}
	if ((*res = ft_width(str, str_index, filler)) == NULL)
		return (-1);
	return (minus);
}
