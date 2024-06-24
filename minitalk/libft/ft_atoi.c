/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:35:26 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 00:40:54 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	long_max(int j, int x)
{
	int	y;

	y = 0;
	if (j >= 19 && x == 1)
		y = -1;
	if (j >= 19 && x == -1)
		y = 0;
	return (y);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	k;
	int	j;

	x = 1;
	k = 0;
	j = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if ((*str == 43 || *str == 45))
	{
		if (*str == 45)
			x *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		k = k * 10 + (*str - 48);
		str++;
		j++;
		if (j == 19)
			return (long_max(j, x));
	}
	k = k * x;
	return (k);
}
