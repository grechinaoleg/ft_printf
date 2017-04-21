/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:30:26 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:31:38 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		add_steps(t_hard **list)
{
	t_hard	*rs;
	int		count;

	count = 0;
	rs = *list;
	if (rs->space)
		count += 1;
	if (rs->sharp)
		count += rs->sharp;
	if (rs->dot)
		count += 1;
	if (rs->plus)
		count += rs->plus;
	if (rs->minus)
		count += rs->minus;
	if (rs->space_count)
		count += rs->space_count;
	if (rs->digit)
		count += rs->digit;
	return (0);
}
