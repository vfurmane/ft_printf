/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:50:59 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/16 15:33:59 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "flags.h"

int	ft_printf(const char *str, ...);
int	ft_parse_format(const char *str, int *str_index, char *buffer, int *i,
	va_list args);
int	ft_flush(char *buffer);
int	ft_precision(const char *str, int *str_index);

#endif
