/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:25:40 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/22 16:00:56 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precision.h"

int	ft_precision(const char *str, int *str_index, va_list args, char *res)
{
	int	precision;

	precision = 1;
	if (str[*str_index] == '.')
	{
		(*str_index)++;
		precision = ft_atoi(&str[*str_index]);
		if (precision < 0)
			precision = -1;
	}
	else if (res[0] == '0')
		precision = -ft_strlen(res);
	else
		precision = -1;
	if (precision == 0 && str[*str_index] == '*')
	{
		(*str_index)++;
		precision = va_arg(args, int);
		if (precision < 0)
			precision = -1;
	}
	else
		while (str[*str_index] >= '0' && str[*str_index] <= '9')
			(*str_index)++;
	return (precision);
}
