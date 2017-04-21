/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:07:22 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:11:50 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*up_num(wint_t w, int length)
{
	char	*s;

	s = ft_strnew((size_t)length);
	s[length--] = '\0';
	if (length == 0)
	{
		s[length] = (char)w;
		return (s);
	}
	s[length--] = (char)((w & 63) + 128);
	if (length == 0)
	{
		s[length] = (char)(((w & 1984) >> 6) + 192);
		return (s);
	}
	s[length--] = (char)(((w & 4032) >> 6) + 128);
	if (length == 0)
	{
		s[length] = (char)(((w & 61440) >> 12) + 224);
		return (s);
	}
	s[length--] = (char)(((w & 258048) >> 12) + 128);
	s[length] = (char)(((w & 1835008) >> 18) + 240);
	return (s);
}

static char	*convert_winttostr(wint_t w)
{
	if (w < 128)
		return (up_num(w, 1));
	if (w < 2048)
		return (up_num(w, 2));
	if (w < 65536)
		return (up_num(w, 3));
	if (w < 1114112)
		return (up_num(w, 4));
	return (0);
}

char		*convert_wstrtostr(wchar_t *s, int max_len)
{
	char	*tmp;
	char	*ret;
	char	*ret_tmp;
	size_t	rz;

	if (!s)
		return (ft_strdup("(null)"));
	rz = 0;
	ret = ft_strdup("");
	while (s[rz])
	{
		tmp = ret;
		ret_tmp = convert_winttostr(s[rz]);
		ret = ft_strjoin(ret, ret_tmp);
		free(ret_tmp);
		if (max_len >= 0 && (int)ft_strlen(ret) > max_len)
		{
			free(ret);
			ret = tmp;
			break ;
		}
		free(tmp);
		rz++;
	}
	return (ret);
}

int			print_ls(wchar_t *str)
{
	char	*s;

	s = convert_wstrtostr(str, g_tochnost);
	return (print_s(s, 1));
}
