/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:00:30 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:01:15 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	if (format)
	{
		va_start(args, format);
		len = parser(&args, format, -1, 0);
		va_end(args);
	}
	return (len);
}
