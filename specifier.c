/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:02 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/23 15:55:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

char	*ft_specifier(const char *str, va_list args, int precision, char *res)
{
	char	*new_str;

	if (*str == 'd' || *str == 'i' || *str == 'u')
		return (ft_print_int(args, precision, *str == 'u'));
	else if (*str == 'c' || *str == '%')
		return (ft_print_char(args));
	else if (*str == 's')
		return (ft_print_string(args, res));
	else if (*str == 'p')
		return (ft_print_address(args));
	else if (*str == 'x' || *str == 'X')
		return (ft_print_hex(args, *str == 'x', precision));
	else
	{
		if ((new_str = malloc(sizeof(*new_str))) == NULL)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	return (NULL);
}
