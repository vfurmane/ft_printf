/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:45:18 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/18 10:12:58 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flush(char *buffer, int size)
{
	int	ret;

	ret = write(1, buffer, size);
	ft_bzero(buffer, size);
	return (ret);
}

int	ft_get_buffer_i(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && i < BUFSIZ)
		i++;
	return (i);
}

int	ft_loop(const char *str, char *buffer, va_list args)
{
	int	i;
	int	total_size;
	int	str_index;

	i = 0;
	total_size = 0;
	str_index = -1;
	while (str[++str_index])
	{
		if (str[str_index] == '%')
		{
			total_size += ft_parse_format(str, &str_index, buffer, args);
			i = ft_get_buffer_i(buffer);
		}
		else
			buffer[i++] = str[str_index];
		if (i == BUFSIZ)
		{
			buffer[BUFSIZ] = '\0';
			total_size += ft_flush(buffer, i);
			i = 0;
		}
	}
	total_size += ft_flush(buffer, i);
	return (total_size);
}

int	ft_printf(const char *str, ...)
{
	int		total_size;
	char	*buffer;
	va_list	args;

	if (BUFSIZ <= 0 || !(buffer = ft_calloc((BUFSIZ + 1), sizeof(*buffer))))
		return (-1);
	va_start(args, str);
	total_size = ft_loop(str, buffer, args);
	free(buffer);
	va_end(args);
	return (total_size);
}
