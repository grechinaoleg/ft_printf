/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:23:02 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:23:42 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_zd(size_t n, int *index)
{
	char	*str;
	int		i;
	int		z;

	if (n == 0)
		z = 0;
	else
		z = 1;
	if (n == (size_t)-9223372036854775808LLU)
		str = ft_strdup("-9223372036854775808");
	else
		str = ft_itoa(n);
	*index += 1;
	i = ft_strlen(str);
	i += get_width(i, 1, 0, 'd');
	print_only_s(str);
	return (i);
}
