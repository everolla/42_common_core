/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:08:15 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:30:55 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*l;
	const char	*k;

	if (dest == 0 && src == 0)
		return (0);
	k = src;
	l = dest;
	i = 0;
	while (i < n)
	{
		l[i] = k[i];
		i++;
	}
	return (l);
}
