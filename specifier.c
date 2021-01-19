/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:02 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/19 10:15:21 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

char	*ft_specifier(const char *str, va_list args, int precision)
{
	char	*res;

	if (*str == 'd' || *str == 'i' || *str == 'u')
		return (ft_print_int(args, precision, *str == 'u'));
	else if (*str == 'c' || *str == '%')
		return (ft_print_char(args));
	else if (*str == 's')
		return (ft_print_string(args));
	else if (*str == 'p')
		return (ft_print_address(args));
	else if (*str == 'x' || *str == 'X')
		return (ft_print_hex(args, *str == 'x'));
	else
	{
		if ((res = malloc(sizeof(*res))) == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	return (NULL);
}
