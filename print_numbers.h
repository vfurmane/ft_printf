/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:57:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 21:16:52 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NUMBERS_H
# define PRINT_NUMBERS_H

# include <stdarg.h>
# include "libft.h"

char	*ft_print_int(va_list args, int precision);
char	*ft_print_hex(va_list args, int lower);

#endif
