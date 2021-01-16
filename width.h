/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:42:33 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/16 15:06:48 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDTH_H
# define WIDTH_H

# include <stdarg.h>
# include "libft.h"

char	*ft_width(const char *str, int *str_index, va_list args, char filler);

#endif
