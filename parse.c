/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:31:24 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 15:07:04 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 1. Check flags
// 2. Check width
// 3. Check precision
// 4. Check length (optionnal, atm)
// 5. Check specifier
// 6. Print according to the parameters

char	*ft_realloc_res(char *res, int len)
{
	if ((res = malloc((len + 1) * sizeof(*res))) == NULL)
		return (NULL);
	res[len] = '\0';
	free(res);
	return (res);
}

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

int		ft_parse_format(const char *str, int *str_index, char *buffer, int *i,
		va_list args)
{
	int		j;
	int		minus;
	int		precision;
	char	*res;
	char	*substr;

	(void)buffer;
	(void)i;
	(*str_index)++;
	minus = ft_flags(str, str_index, args, &res);
	precision = ft_precision(str, str_index, args);
	substr = ft_specifier(&str[*str_index], args);
	if (substr == NULL || (res = ft_format_str(res, substr, minus)) == NULL)
		return (-1);
	j = 0;
	while (res[j])
	{
		if (*i == BUFSIZ)
		{
			ft_flush(buffer, *i);
			*i = 0;
		}
		buffer[(*i)++] = res[j++];
	}
	free(substr);
	free(res);
	return (0);
}
