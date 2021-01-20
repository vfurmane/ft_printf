/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:56:41 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/20 12:45:26 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_numbers.h"

char	*ft_realloc_nbr(char *str, int len)
{
	int		i;
	int		str_len;
	char	*new_str;

	if ((new_str = malloc((len + 1) * sizeof(*new_str))) == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_memset(new_str, '0', len);
	str_len = ft_strlen(str);
	i = -1;
	while (str[++i])
		new_str[len - i - 1] = str[str_len - i - 1];
	new_str[len] = '\0';
	free(str);
	return (new_str);
}

char	*ft_print_int(va_list args, long int precision, int isunsigned)
{
	long int	nbr;
	char		*str;

	if (isunsigned == 1)
		nbr = va_arg(args, unsigned int);
	else
		nbr = va_arg(args, int);
	if (isunsigned == 1 && nbr < 0)
		str = ft_long_itoa((unsigned int)-nbr);
	else if (isunsigned == 1)
		str = ft_long_itoa((unsigned int)nbr);
	else if (precision == 0 && nbr == 0)
		str = ft_calloc(1, sizeof(*str));
	else
		str = ft_long_itoa((int)nbr);
	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < precision)
		str = ft_realloc_nbr(str, precision);
	return (str);
}

char	*ft_print_hex(va_list args, int lower, int precision)
{
	int				len;
	char			*set;
	char			*str;
	unsigned int	nb;

	set = "0123456789ABCDEF";
	if (lower == 1)
		set = "0123456789abcdef";
	nb = va_arg(args, unsigned int);
	if (nb < 0)
		nb = -nb;
	len = ft_count_digits_hex(nb);
	if ((str = malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[len-- - 1] = set[nb % 16];
		nb /= 16;
	}
	if (ft_strlen(str) < precision)
		str = ft_realloc_nbr(str, precision);
	return (str);
}
