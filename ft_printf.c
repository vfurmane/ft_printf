/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:45:18 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 14:10:20 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 1. Read the string and copy into buffer
// 2. When there is '%' which isn't after a '\', parse parameters
//    - if block for specifier
// 3. Put the result into the buffer
// 4. Flush the buffer once it is full (check that at each character copied)

int	ft_flush(char *buffer, int size)
{
	write(1, buffer, size);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		str_index;
	char	*buffer;
	va_list	args;

	if (BUFSIZ <= 0 || !(buffer = malloc((BUFSIZ + 1) * sizeof(*buffer))))
		return (-1);
	i = 0;
	va_start(args, str);
	str_index = 0;
	while (str[str_index])
	{
		if (str[str_index] == '%')
			ft_parse_format(str, &str_index, buffer, &i, args);
		else
			buffer[i++] = str[str_index];
		if (i == BUFSIZ)
		{
			buffer[BUFSIZ] = '\0';
			ft_flush(buffer, i);
			i = 0;
		}
		str_index++;
	}
	ft_flush(buffer, i);
	free(buffer);
	va_end(args);
	return (0);
}
