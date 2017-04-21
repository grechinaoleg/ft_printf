/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_globals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:33:44 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:34:50 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	clean_globals(void)
{
	g_space_start = 0;
	g_tochnost = -1;
	g_plus_pl = 0;
	g_zero = 0;
	g_sharp = 0;
	g_width = 0;
	g_space = 0;
	g_minus = 0;
	g_per = 0;
}
