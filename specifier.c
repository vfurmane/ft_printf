/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:02 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/24 13:44:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

char	*ft_create_string(char chr)
{
	char	*new_str;

	if ((new_str = malloc(sizeof(*new_str))) == NULL)
		return (NULL);
	new_str[0] = chr;
	return (new_str);
}

char	*ft_specifier(const char *str, va_list args, int precision)
{
	if (*str == 'd' || *str == 'i' || *str == 'u')
		return (ft_print_int(args, precision, *str == 'u'));
	else if (*str == 'c')
		return (ft_print_char(args));
	else if (*str == 's')
		return (ft_print_string(args, precision));
	else if (*str == 'p')
		return (ft_print_address(args, precision));
	else if (*str == 'x' || *str == 'X')
		return (ft_print_hex(args, *str == 'x', precision));
	else if (*str == '%')
		return (ft_create_string('%'));
	else
		return (ft_create_string('\0'));
	return (NULL);
}
