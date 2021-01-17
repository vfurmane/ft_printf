/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:56:41 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 21:25:17 by vfurmane         ###   ########.fr       */
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

int		ft_count_digits_hex_sign(int nbr)
{
	int				len;
	unsigned int	nb;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len++;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

char	*ft_print_hex(va_list args, int lower)
{
	int				nbr;
	int				len;
	char			*set;
	char			*str;
	unsigned int	nb;

	set = "0123456789ABCDEF";
	if (lower == 1)
		set = "0123456789abcdef";
	nbr = va_arg(args, int);
	nb = nbr;
	if (nbr < 0)
		nb = -nbr;
	len = ft_count_digits_hex_sign(nb);
	if ((str = malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	str[0] = '-';
	str[len] = '\0';
	while (nb)
	{
		str[len-- - 1] = set[nb % 16];
		nb /= 16;
	}
	return (str);
}
