/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:02 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 10:59:56 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

char	*ft_specifier(const char *str, va_list args)
{
	if (*str == 'd' || *str == 'i')
		return (ft_itoa(va_arg(args, int)));
	return (NULL);
}
