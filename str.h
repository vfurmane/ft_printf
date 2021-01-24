/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:54:03 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/24 15:06:01 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>

char	*ft_long_itoa(long int nbr);
int		ft_count_digits_hex(long int nbr);
char	*ft_long_itoa_hex(long int nbr, char *set);

#endif
