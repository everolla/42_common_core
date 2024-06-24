/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everolla <everolla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:14:56 by everolla          #+#    #+#             */
/*   Updated: 2023/01/26 01:30:28 by everolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*skrt;
	unsigned int	i;

	i = 0;
	if (s == '\0')
		return (0);
	while (s[i])
		i++;
	skrt = malloc((i + 1) * sizeof(char));
	if (skrt == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		skrt[i] = f(i, s[i]);
		i++;
	}
	skrt[i] = '\0';
	return (skrt);
}
