/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:31:24 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/21 12:05:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_str(char *res, char *str, int minus)
{
	int	i;
	int	res_len;
	int	str_len;

	res_len = ft_strlen(res);
	str_len = ft_strlen(str);
	if (res_len < str_len)
	{
		free(res);
		if ((res = malloc((str_len + 1) * sizeof(*res))) == NULL)
			return (NULL);
		res_len = str_len;
		res[res_len] = '\0';
	}
	i = -1;
	if (minus == 0)
		while (str[++i])
			res[res_len - i - 1] = str[str_len - i - 1];
	else
		while (str[++i])
			res[i] = str[i];
	return (res);
}

int		ft_copy_in_buffer(char *res, char *buffer, int i)
{
	int	j;
	int	total_size;

	j = 0;
	total_size = 0;
	while (res[j])
	{
		if (i == BUFSIZ)
		{
			total_size = ft_flush(buffer, i);
			i = 0;
		}
		buffer[i++] = res[j++];
	}
	return (total_size);
}

char	*ft_replace_precision(char *res, int precision)
{
	if (precision == 0)
	{
		ft_memset(res, ' ', ft_strlen(res));
	}
	return (res);
}

int		ft_check_percentage(const char *specifier)
{
	if (*specifier == 'c' || *specifier == 'd' || *specifier == 'i' ||
			*specifier == 's' || *specifier == 'u' || *specifier == 'x' ||
			*specifier == 'X' || *specifier == 'p' || *specifier == '%')
		return (0);
	return (1);
}

int		ft_parse_format(const char *str, int *str_index, char *buffer,
		va_list args)
{
	int		total_size;
	int		minus;
	int		precision;
	char	*res;
	char	*substr;

	(*str_index)++;
	total_size = *str_index;
	minus = ft_flags(str, str_index, args, &res);
	if (minus == -1)
		return (-1);
	precision = ft_precision(str, str_index, args, res);
	res = ft_replace_precision(res, precision);
	substr = ft_specifier(&str[*str_index], args, precision);
	if (substr == NULL || (res = ft_format_str(res, substr, minus)) == NULL)
	{
		free(res);
		free(substr);
		return (-1);
	}
	(*str_index) -= ft_check_percentage(&str[*str_index]);
	total_size = ft_copy_in_buffer(res, buffer, ft_get_buffer_i(buffer));
	free(substr);
	free(res);
	return (total_size);
}
