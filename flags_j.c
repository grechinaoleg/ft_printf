/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_j.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:48:39 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:50:03 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		j_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i] == 'j' && (str[i + 1] == 'd' || str[i + 1] == 'D'
				|| str[i + 1] == 'i'))
		return (print_jd(va_arg(*args, intmax_t), index));
	else if (str[i] == 'j' && (str[i + 1] == 'u' || str[i + 1] == 'U'))
		return (print_ju_bg(va_arg(*args, uintmax_t), index));
	else if (str[i] == 'j' && (str[i + 1] == 'o' || str[i + 1] == 'O'))
		return (print_jo(va_arg(*args, uintmax_t), 0, 0, 0));
	else if (str[i] == 'j' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		return (print_jx(va_arg(*args, uintmax_t), str[i + 1], index, 1));
	return (-1);
}
