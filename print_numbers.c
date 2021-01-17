/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:56:41 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 17:43:01 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_numbers.h"

char	*ft_realloc_nbr(char *str, int len)
{
	int		i;
	int		str_len;
	char	*new_str;

	if ((new_str = malloc((len + 1) * sizeof(*new_str))) == NULL)
		return (NULL);
	ft_memset(new_str, '0', len);
	str_len = ft_strlen(str);
	i = -1;
	while (str[++i])
		new_str[len - i - 1] = str[str_len - i - 1];
	new_str[len] = '\0';
	free(str);
	return (new_str);
}

char	*ft_print_int(va_list args, int precision)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	if (ft_strlen(str) < precision)
		str = ft_realloc_nbr(str, precision);
	return (str);
}
