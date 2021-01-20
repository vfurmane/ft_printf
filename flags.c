/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:49:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/20 16:46:02 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int	ft_flags(const char *str, int *str_index, va_list args, char **res)
{
	int		minus;
	int		len;
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
	len = 0;
	if (str[*str_index] == '*')
		len = va_arg(args, int);
	if (len < 0)
		minus = 1;
	if (minus == 1)
		filler = ' ';
	if ((*res = ft_width(str, str_index, len, filler)) == NULL)
		return (-1);
	return (minus);
}
