/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:29:28 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:15:46 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ultima(const char *haystack, const char *needle, size_t j,
		size_t len)
{
	int	i;
	int	a;

	i = 0;
	a = j;
	while (needle[i] == haystack[j] && j < len)
	{
		if (needle[i + 1] == '\0')
			return ((char *)&haystack[a]);
		i++;
		j++;
	}
	return ((char *)0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		a;
	size_t	j;
	char	*r;

	a = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[a] != '\0')
	{
		if (needle[0] == haystack[a])
		{
			j = a;
			r = ultima(haystack, needle, j, len);
			if (r != 0)
				return (r);
		}
		a++;
	}
	return (0);
}
