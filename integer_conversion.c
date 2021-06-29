/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:10:11 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/17 14:10:14 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	integer_aux_1 (int count, int a)
{
	if (g_flags.negative)
		g_flags.negative = print_n_char(1, '-') - 1;
	count = count + print_n_char(a, '0');
	return (count);
}

static int	integer_aux_2 (int b, int count)
{
	if (!g_flags.minus && !g_flags.zero)
	{
		count = count + print_n_char(b, ' ');
		if (g_flags.negative)
			g_flags.negative = print_n_char(1, '-') - 1;
	}
	if (!g_flags.minus && g_flags.zero)
	{
		if (g_flags.negative)
			g_flags.negative = print_n_char(1, '-') - 1;
		count = count + print_n_char(b, '0');
	}
	return (count);
}

static int	interger_aux_3 (char *s, int l, int a, int b)
{
	int	count;

	count = 0;
	if (a)
		count = integer_aux_1(count, a);
	if (g_flags.negative)
		print_n_char(1, '-');
	count = count + final_output(s);
	if (g_flags.minus && g_flags.with > l)
		count = count + print_n_char(b, ' ');
	return (count);
}

static char	*integer_aux_4(long long int *d, int *l, int *a)
{
	char	*s;

	*d = *d * (-1);
	g_flags.negative = 1;
	s = ft_itoa_base(*d, DECIMAL);
	*l = ft_strlen(s);
	if (g_flags.dot)
		g_flags.zero = 0;
	if (g_flags.percision > *l)
	{
		*a = g_flags.percision - *l;
		*l = g_flags.percision;
	}
	return (s);
}

int	integer_conversion(long long int d)
{
	char	*s;
	int		a;
	int		b;
	int		l;
	int		count;

	count = 0;
	b = 0;
	a = 0;
	if (d >= 0)
		return (unsigned_int_conversion(d));
	s = integer_aux_4(&d, &l, &a);
	if (g_flags.with > l)
	{
		b = g_flags.with - l - 1;
		count = integer_aux_2(b, count);
	}
	count = count + interger_aux_3(s, l, a, b);
	free(s);
	return (count + 1);
}
