/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:29:28 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:15:58 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		z;
	char	*g;

	i = 0;
	z = -1;
	g = (char *)s;
	if (c == '\0')
		return (&g[ft_strlen(s)]);
	while (g[i])
	{
		if (g[i] == c)
			z = i;
		i++;
	}
	if (z >= 0)
		return (&g[z]);
	else
		return (0);
}
