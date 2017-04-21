/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:59:15 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:00:55 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_eightbit_long_l(unsigned long long int n)
{
	char				*str;
	int					i;
	unsigned long int	tmp;

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

int			print_llo(unsigned long long int n, int *index, int co, int x)
{
	char	*s;
	int		len;
	int		z;

	x = 0;
	if (n == 0)
		z = 0;
	else
		z = 1;
	if (co)
		*index += co;
	s = ft_eightbit_long_l(n);
	len = ft_strlen(s);
	len += get_width(len, z, 0, 'o');
	print_only_s(s);
	return (len);
}
