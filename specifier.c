/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:02 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 18:50:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

char	*ft_specifier(const char *str, va_list args, int precision)
{
	if (*str == 'd' || *str == 'i')
		return (ft_print_int(args, precision));
	else if (*str == 'c' || *str == '%')
		return (ft_print_char(args));
	else if (*str == 's')
		return (ft_print_string(args));
	return (NULL);
}
