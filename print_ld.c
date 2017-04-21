/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:55:14 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:56:33 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	up_g_zero_ld(long int *n)
{
	*n = *n * -1;
}

int		print_ld(long n, int *index)
{
	char	*str;
	int		i;
	int		z;

	if (n < 0)
		z = 0;
	else
		z = 1;
	if (n < 0)
		up_g_zero_ld(&n);
	if (n == (long long)-9223372036854775808LLU)
		str = ft_strdup("9223372036854775808");
	else
		str = ft_itoa(n);
	*index += 1;
	i = ft_strlen(str);
	i += get_width(i, z, 0, 'd');
	print_only_s(str);
	return (i);
}
