/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:55:58 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:57:10 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_charjoin(char *str, char c)
{
	int		len;
	int		i;
	char	*s;

	i = 0;
	len = ft_strlen(str);
	s = malloc(sizeof(char) * len + 2);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = '\0';
	free(str);
	return (s);
}
