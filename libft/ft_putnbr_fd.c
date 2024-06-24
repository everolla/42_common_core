/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:09:26 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:27:54 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	z;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
		if (n == -2147483648)
		{
			write(fd, &"-2147483648", 11);
			i = -1;
			n = 0;
		}
	}
	z = (n % 10) + '0';
	if (z == 0)
		z = n + '0';
	if (i == 1)
		write(fd, "-", 1);
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	if (i != -1)
		write(fd, &z, 1);
}
