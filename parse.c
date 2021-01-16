/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:31:24 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/16 15:31:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 1. Check flags
// 2. Check width
// 3. Check precision
// 4. Check length
// 5. Check specifier

int	ft_parse_format(const char *str, int *str_index, char *buffer, int *i,
		va_list args)
{
	int		precision;
	char	*res;

	(void)buffer; /* ===== DELETE ===== */
	(void)i; /* ===== DELETE ===== */
	(*str_index)++;
	ft_flags(str, str_index, args, &res);
	precision = ft_precision(str, str_index);
	return (0);
}
