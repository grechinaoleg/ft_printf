/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:35:02 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:36:47 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		find_simple(char *str, int i, va_list *args, int *index)
{
	int	ret;

	ret = 0;
	*index = *index + 1;
	while (str[i])
	{
		if ((ret = s_flags(str, i, args, index)) >= 0)
			return (ret);
		if ((ret = l_flags(str, i, args, index)) >= 0)
			return (ret);
		if ((ret = ll_flags(str, i, args, index)) >= 0)
			return (ret);
		if ((ret = z_flags(str, i, args, index)) >= 0)
			return (ret);
		if ((ret = h_flags(str, i, args, index)) >= 0)
			return (ret);
		if ((ret = hh_flags(str, i, args, index)) >= 0)
			return (ret);
		if ((ret = j_flags(str, i, args, index)) >= 0)
			return (ret);
		i++;
	}
	return (0);
}
