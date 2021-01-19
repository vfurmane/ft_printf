/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:25:40 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/19 13:34:24 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precision.h"

int	ft_precision(const char *str, int *str_index, va_list args)
{
	int	precision;

	precision = 1;
	if (str[*str_index] == '.')
	{
		(*str_index)++;
		precision = ft_atoi(&str[*str_index]);
	}
	if (precision == 0 && str[*str_index] == '*')
	{
		(*str_index)++;
		precision = va_arg(args, int);
	}
	else
		while (str[*str_index] >= '0' && str[*str_index] <= '9')
			(*str_index)++;
	return (precision);
}
