/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:53:50 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 22:00:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_count_digits(long int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	i += nbr < 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_long_itoa(long int nbr)
{
	int				i;
	int				len;
	char			*str;
	unsigned int	nb;

	len = ft_count_digits(nbr);
	if (!(str = malloc((len + 1) * sizeof(*str))))
		return (NULL);
	str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	if (nbr <= 0)
		nb = -nbr;
	else
		nb = nbr;
	i = len;
	while (nb)
	{
		i--;
		str[i] = nb % 10 + '0';
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}

int		ft_count_digits_hex(int nbr)
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
