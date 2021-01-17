/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:47:32 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/17 09:47:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

# include <stdarg.h>

int	ft_specifier(const char *str, char **res, va_list args);

#endif
