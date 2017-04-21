/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:36:57 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:41:55 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			simple(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 's'
			|| c == 'S' || c == 'b' || c == 'c' || c == 'C'
			|| c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'p' || c == 'f' || c == 'F' || c == 'l'
			|| c == 'z' || c == 'o' || c == 'O'
			|| c == 'j' || c == 'h')
		return (1);
	return (0);
}

static int	min_s_flags(char *str, int i, va_list *args)
{
	if (str[i] == 'f' || str[i] == 'F')
		return (print_f(va_arg(*args, double), 0, 0, 0));
	else if (str[i] == 'b')
		return (print_p(va_arg(*args, void *), 'b'));
	return (-1);
}

int			s_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i] == 'd' || str[i] == 'i')
		return (print_d_i((int)va_arg(*args, intmax_t), 1));
	else if (str[i] == 'D')
		return (print_ld((long)va_arg(*args, long int), index + 1));
	else if (str[i] == 's')
		return (print_s(va_arg(*args, char *), 1));
	else if (str[i] == 'S')
		return (print_ls(va_arg(*args, wchar_t*)));
	else if (str[i] == 'c' || str[i] == 'C')
		return (print_c(va_arg(*args, int)));
	else if (str[i] == 'u')
		return (print_u_bg((unsigned int)va_arg(*args, intmax_t)));
	else if (str[i] == 'U')
		return (print_lu_bg((unsigned long int)va_arg(*args, intmax_t),
					index + 1));
	else if (str[i] == 'x' || str[i] == 'X')
		return (print_x((unsigned int)va_arg(*args, intmax_t), str[i], 0, 0));
	else if (str[i] == 'p')
		return (print_p(va_arg(*args, void *), 'p'));
	else if (str[i] == 'o')
		return (print_o((unsigned int)va_arg(*args, intmax_t), 0, 0, 0));
	else if (str[i] == 'O')
		return (print_lo(va_arg(*args, unsigned long int), 0, 0, 0));
	else
		return (min_s_flags(str, i, args));
}
