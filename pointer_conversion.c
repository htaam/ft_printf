/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:29:48 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/31 12:29:50 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_conversion(unsigned long long int d)
{
	char	*s;
	int		a;
	int		b;

	b = 0;
	if (!d && g_flags.dot)
		s = ft_substr("", 0, 0);
	else
		s = ft_itoa_base_unsigned(d, HEXA_LOWER);
	if (g_flags.with > ft_strlen(s) + ft_strlen("0x"))
	{
		b = g_flags.with - ft_strlen(s) - ft_strlen("0x");
		if (!g_flags.minus)
			print_n_char(b, ' ');
	}
	a = final_output("0x") + final_output(s);
	free(s);
	if (g_flags.minus && g_flags.with > ft_strlen(s) + ft_strlen("0x"))
		print_n_char(b, ' ');
	return (a + b);
}
