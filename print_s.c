/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:17:24 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:18:43 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_only_s(char *s)
{
	int		len;

	len = (int)ft_strlen(s);
	write(1, s, (unsigned int)len * CH_SIZE);
	return (len);
}

int		print_s(char *str, int width)
{
	int		len;
	int		tmp_len;
	char	*s;
	int		i;

	if (!str)
		str = ft_strdup("(null)");
	i = 0;
	s = ft_strdup("");
	while (str[i])
	{
		if (g_tochnost != -1 && i == (g_tochnost))
			break ;
		s = ft_charjoin(s, str[i]);
		i++;
	}
	len = (int)ft_strlen(s);
	tmp_len = len;
	if (width)
		len += get_width(len, 0, 1, 's');
	write(1, s, (unsigned int)tmp_len * CH_SIZE);
	return (len);
}
