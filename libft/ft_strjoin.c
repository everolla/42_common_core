/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:10:49 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:10:50 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		z;
	int		k;
	char	*s3;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1);
	z = ft_strlen(s2);
	s3 = malloc((z + i + 1) * sizeof(char));
	if (!s3)
		return (0);
	k = 0;
	while (k < i)
	{
		s3[k] = s1[k];
		k++;
	}
	k = 0;
	while (k <= z)
	{
		s3[k + i] = s2[k];
		k++;
	}
	return (s3);
}
