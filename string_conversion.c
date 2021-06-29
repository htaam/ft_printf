/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:31:47 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/17 14:31:49 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	string_aux_1(char *s, int *l, int *b)
{
	if (g_flags.percision < ft_strlen(s) && g_flags.dot)
		*l = g_flags.percision;
	else
		*l = ft_strlen(s);
	if (g_flags.with > *l)
	{
		*b = g_flags.with - *l;
		if (!g_flags.minus & !g_flags.zero)
			print_n_char(*b, ' ');
	}
}

int	string_conversion(char *s)
{
	int	b;
	int	a;
	int	char_count;
	int	l;

	a = 0;
	b = 0;
	char_count = 0;
	if (!s)
		return (string_conversion("(null)"));
	string_aux_1(s, &l, &b);
	if (g_flags.dot)
	{
		while (a < l)
			char_count = char_count + print_n_char(1, s[a++]);
	}
	else
	{
		ft_putstr_fd(s, 1);
		char_count = ft_strlen(s);
	}
	if (g_flags.minus && g_flags.with > l)
		print_n_char(b, ' ');
	return (char_count + b);
}
