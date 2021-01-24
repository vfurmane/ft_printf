/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:45:18 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/23 20:17:06 by vfurmane         ###   ########.fr       */
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

int	ft_loop(const char *str, t_buffer *buffer, va_list args)
{
	int	ret;
	int	total_size;
	int	str_index;

	total_size = 0;
	str_index = -1;
	while (str[++str_index])
	{
		if (str[str_index] == '%')
		{
			if ((ret = ft_parse_format(str, &str_index, buffer, args)) == -1)
				return (-1);
			total_size += ret;
		}
		else
			buffer->content[buffer->i++] = str[str_index];
		if (buffer->i == BUFSIZ)
			total_size += ft_flush(buffer->content, buffer->i);
		buffer->i *= buffer->i != BUFSIZ;
	}
	total_size += ft_flush(buffer->content, buffer->i);
	return (total_size);
}

int	ft_printf(const char *str, ...)
{
	int			total_size;
	t_buffer	*buffer;
	va_list		args;

	if (BUFSIZ <= 0 || !(buffer = malloc(sizeof(*buffer))) ||
			!(buffer->content = ft_calloc((BUFSIZ + 1), sizeof(*buffer->content))))
		return (-1);
	va_start(args, str);
	buffer->i = 0;
	buffer->content[BUFSIZ] = '\0';
	total_size = ft_loop(str, buffer, args);
	free(buffer->content);
	free(buffer);
	va_end(args);
	if (total_size == -1)
		return (-1);
	return (total_size);
}
