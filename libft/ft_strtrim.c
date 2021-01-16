/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:50:07 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/08 15:37:58 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimlen(const char *str, const char *set)
{
	int	i;
	int	trim_len;

	trim_len = ft_strlen(str);
	while (ft_strchr(set, str[trim_len - 1]) != NULL && trim_len > 0)
		trim_len--;
	if (trim_len == 0)
		return (0);
	i = 0;
	while (ft_strchr(set, str[i]) != NULL && str[i])
		i++;
	trim_len -= i;
	return (trim_len);
}

char		*ft_strtrim(const char *str, const char *set)
{
	int		i;
	int		trim_len;
	char	*new_str;

	trim_len = ft_trimlen(str, set);
	if (!(new_str = malloc((trim_len + 1) * sizeof(*new_str))))
		return (NULL);
	i = 0;
	while (ft_strchr(set, str[i]) != NULL && str[i])
		i++;
	ft_strlcpy(new_str, &str[i], trim_len + 1);
	return (new_str);
}
