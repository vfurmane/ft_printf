/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:09:50 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/24 15:04:53 by vfurmane         ###   ########.fr       */
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

char	*ft_print_string(va_list args, int precision)
{
	int		str_len;
	char	*str;
	char	*ref;

	ref = va_arg(args, char*);
	if (ref == NULL)
		ref = "(null)";
	str_len = ft_strlen(ref);
	if (precision >= 0 && precision < str_len)
		str_len = precision;
	if ((str = malloc((str_len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	ft_strlcpy(str, ref, str_len + 1);
	return (str);
}

char	*ft_print_address(va_list args, int precision)
{
	char			*str;
	char			*hex_str;
	long int		nbr;

	nbr = va_arg(args, long int);
	if (precision == 0 && nbr == 0)
		str = ft_calloc(3, sizeof(*str));
	else
		str = ft_long_itoa_hex(nbr, "0123456789abcdef");
	hex_str = ft_strjoin("0x", str);
	free(str);
	return (hex_str);
}
