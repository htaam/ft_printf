/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:34:57 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/31 11:35:02 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_conversion(void)
{
	return (char_conversion('%'));
}

static void	char_aux_1(int *b)
{
	if (g_flags.with > 1)
	{
		*b = g_flags.with - 1;
		if (!g_flags.minus && !g_flags.zero)
			print_n_char(*b, ' ');
		if (!g_flags.minus && g_flags.zero)
			print_n_char(*b, '0');
	}
}

int	char_conversion(char c)
{
	int	b;

	b = 0;
	char_aux_1(&b);
	print_n_char(1, c);
	if (g_flags.with > 1)
	{
		b = g_flags.with - 1;
		if (g_flags.minus)
			print_n_char(b, ' ');
	}
	return (1 + b);
}
