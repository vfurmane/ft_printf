/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:57:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 22:03:02 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NUMBERS_H
# define PRINT_NUMBERS_H

# include <stdarg.h>
# include "str.h"
# include "libft.h"

char	*ft_print_int(va_list args, long int precision, int isunsigned);
char	*ft_print_hex(va_list args, int lower);

#endif
