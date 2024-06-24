/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:16:07 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:16:08 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_getend(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = ft_strlen(s1) - 1;
	j = -1;
	while (++j < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	i;
	char	*f;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return ((char *)s1);
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	f = (char *)malloc(sizeof(char) * (end - start + 1));
	if (f == '\0')
		return (0);
	i = 0;
	while (start < end)
		f[i++] = s1[start++];
	f[i] = '\0';
	return (f);
}
