/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:42:45 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:43:44 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_only_c(char c)
{
	write(1, &c, CH_SIZE);
	return (1);
}

int		print_c(char c)
{
	int		len;

	len = 1;
	if (g_space_start)
		len += get_width(1, 0, 1, 'c');
	write(1, &c, CH_SIZE);
	return (len);
}
