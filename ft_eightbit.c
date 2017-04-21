/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eightbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:57:22 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:58:35 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_eightbit(unsigned int n)
{
	char			*str;
	int				i;
	unsigned int	tmp;

	tmp = n;
	i = 0;
	while (tmp > 7)
	{
		tmp = (tmp / 8);
		i++;
	}
	if ((str = (char *)malloc(sizeof(str) * (i + 1))))
	{
		str[i + 1] = '\0';
		while (i >= 0)
		{
			str[i] = (n % 8 + 48);
			n = n / 8;
			i--;
		}
	}
	return (str);
}
