/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:09:50 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 18:15:27 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_chars.h"

char *ft_print_char(va_list args)
{
	char	*str;

	if ((str = malloc(2 * sizeof(*str))) == NULL)
		return (NULL);
	str[0] = (char)va_arg(args, int);
	str[1] = '\0';
	return (str);
}
