/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:32 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/23 15:48:47 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

# include <stdarg.h>
# include "print_chars.h"
# include "print_numbers.h"
# include "libft.h"

char	*ft_specifier(const char *str, va_list args, int precision, char *res);

#endif
