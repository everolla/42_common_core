/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:39:11 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:22:19 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conto(int n)
{
	int	i;
	int	r;

	i = 0;
	r = n;
	if (n < 0)
	{
		i++;
		r = -n;
	}
	if (n == 0)
		return (1);
	while (r > 0)
	{
		i++;
		r = r / 10;
	}
	return (i);
}

static char	*tutta(char *eskere, int i, long int k)
{
	eskere[i] = 0;
	i--;
	while (k > 0)
	{
		eskere[i] = (k % 10) + 48;
		k = k / 10;
		i--;
	}
	return (eskere);
}

char	*ft_itoa(int n)
{
	char	*eskere;
	int		k;

	eskere = malloc((ft_conto(n) + 1) * sizeof(char));
	if (!eskere)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(eskere, "-2147483648", 12);
	else
	{
		k = n;
		if (n < 0)
		{
			k = -n;
			eskere[0] = '-';
		}
		if (k == 0)
			eskere[0] = '0';
		if (k > 0)
			return (tutta(eskere, ft_conto(n), k));
		eskere[ft_conto(n)] = 0;
	}
	return (eskere);
}
