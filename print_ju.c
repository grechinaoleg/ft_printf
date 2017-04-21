/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ju.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:50:46 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:51:30 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	print_ju(uintmax_t n, char **z)
{
	if (n >= 10)
		return (print_ju(n / 10, z) + print_ju(n % 10, z));
	*z = ft_charjoin(*z, n + 48);
	return (1);
}

int			print_ju_bg(uintmax_t n, int *index)
{
	char	*s;
	int		len;

	*index = *index + 1;
	s = ft_strdup("");
	print_ju(n, &s);
	len = ft_strlen(s);
	len += get_width(len, 1, 0, 'u');
	print_only_s(s);
	return (len);
}
