/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:26:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/21 10:55:15 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECISION_H
# define PRECISION_H

# include <stdarg.h>
# include "libft.h"

int	ft_precision(const char *str, int *str_index, va_list args, char *res);

#endif
