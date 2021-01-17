/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:09:50 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 21:55:05 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_chars.h"

char	*ft_print_char(va_list args)
{
	char	*str;

	if ((str = malloc(2 * sizeof(*str))) == NULL)
		return (NULL);
	str[0] = (char)va_arg(args, int);
	str[1] = '\0';
	return (str);
}

char	*ft_print_string(va_list args)
{
	int		str_len;
	char	*str;
	char	*ref;

	ref = va_arg(args, char*);
	str_len = ft_strlen(ref);
	if ((str = malloc((str_len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	ft_strlcpy(str, ref, str_len + 1);
	return (str);
}

char	*ft_print_address(va_list args)
{
	int					i;
	int					len;
	char				*str;
	unsigned int		nbr;
	
	nbr = (unsigned int)va_arg(args, int);
	len = ft_count_digits_hex(nbr) + 2;
	if ((str = malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	i = 0;
	while (nbr)
	{
		str[len - i - 1] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
		i++;
	}
	str[0] = '0';
	str[1] = 'x';
	str[len] = '\0';
	return (str);
}
