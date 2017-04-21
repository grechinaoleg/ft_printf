/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:23:51 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:24:36 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_zu(intmax_t n, int *index)
{
	char	*str;
	int		i;

	str = ft_itoa_base(n, 10);
	*index += 1;
	i = ft_strlen(str);
	i += get_width(i, 1, 0, 'd');
	print_only_s(str);
	return (i);
}
