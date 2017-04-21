/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:09:45 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:30:56 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	find_hard_min(t_hard **list, long long int *digit,
		char *str, int *index)
{
	t_hard	*rs;

	rs = *list;
	*index += (rs->end - rs->index);
	if (rs->sharp)
		g_sharp = 1;
	if (rs->digit)
		*digit = valid_digit(str, &rs, 0);
	if (rs->digit)
		g_width = valid_width(str, &rs, (int)*digit);
	if (rs->dot)
		g_tochnost = valid_toch(str, &rs, 0);
	else
		g_tochnost = -1;
	if (rs->minus)
		g_minus = 1;
	if (rs->space)
		g_space = 1;
	if (rs->plus)
		g_plus_pl = 1;
}

static void	find_hard_min2(t_hard **list, long long *digit, int *tmp_count)
{
	t_hard	*rs;

	rs = *list;
	if (*digit && rs->digit && rs->plus && !rs->minus)
		g_space_start = *digit - *tmp_count;
	else if (*digit && !rs->plus && !rs->minus)
		g_space_start = *digit - *tmp_count;
}

static void	find_hard_min3(t_hard **list, int *tmp_count)
{
	t_hard	*rs;
	int		i;

	rs = *list;
	if (g_width && rs->minus)
	{
		i = *tmp_count;
		while (g_width > i)
		{
			*tmp_count += print_only_c(' ');
			i++;
		}
	}
}

int			find_hard(char *str, t_hard **list, int *index, va_list *args)
{
	t_hard			*rs;
	long long int	digit;
	int				count;
	int				tmp_count;

	rs = *list;
	digit = 0;
	count = 0;
	tmp_count = 0;
	find_hard_min(list, &digit, str, index);
	find_hard_min2(list, &digit, &tmp_count);
	*index += add_steps(list);
	tmp_count += find_simple(str, rs->end, args, index);
	find_hard_min3(list, &tmp_count);
	count += tmp_count;
	clean_globals();
	return (count);
}

int			parser(va_list *args, const char *format, int i, int length)
{
	char		*str;
	t_hard		*list;

	str = (char *)format;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			if (hard_valid(&i, str, &list))
				length += find_hard(str, &list, &i, args);
			else if (min_width(str, &i, 0, 0))
				length += get_min_width();
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			length += print_only_c(str[i++]);
		else
			length += print_only_c(str[i]);
	}
	return (length);
}
