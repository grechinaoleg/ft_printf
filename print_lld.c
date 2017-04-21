/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:56:40 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:58:05 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	up_g_zero_lld(long long int *n)
{
	*n = *n * -1;
}

int		print_lld(long long int n, int *index)
{
	char	*str;
	int		i;
	int		z;

	if (n < 0)
		z = 0;
	else
		z = 1;
	if (n == (long long)-9223372036854775808LLU)
		str = ft_strdup("9223372036854775808");
	else
	{
		if (n < 0)
			up_g_zero_lld(&n);
		str = ft_itoa(n);
	}
	*index += 2;
	i = ft_strlen(str);
	i += get_width(i, z, 0, 'd');
	print_only_s(str);
	return (i + 1);
}
