/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:58:46 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:59:59 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_base(unsigned long long value, int base)
{
	char				*str;
	int					i;
	unsigned long long	tmp;
	char				*b;

	b = "0123456789ABCDEF";
	i = 1;
	tmp = value;
	while (value /= base)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = b[tmp % base];
		tmp /= base;
	}
	return (str);
}
