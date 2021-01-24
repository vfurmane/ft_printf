/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:10:31 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/24 11:35:02 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_CHARS_H
# define PRINT_CHARS_H

# include <stdarg.h>
# include <stdlib.h>
# include "str.h"
# include "libft.h"

char	*ft_print_char(va_list args);
char	*ft_print_string(va_list args, int precision);
char	*ft_print_address(va_list args);

#endif
