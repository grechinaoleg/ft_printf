/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:28:56 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:29:57 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		add_hard(int index, int *s, t_hard **list)
{
	t_hard *test;

	if (!(test = (t_hard*)malloc(sizeof(t_hard))))
		return (0);
	test->space = s[0];
	test->sharp = s[1];
	test->dot = s[2];
	test->digit = s[3];
	test->plus = s[4];
	test->minus = s[5];
	test->index = index;
	test->end = s[6];
	test->space_count = s[7];
	*list = test;
	return (1);
}
