/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:04:34 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/31 15:04:36 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_determinations(va_list args, int i, const char *buffer)
{
	int		char_printed;
	int		b;
	int		a;
	char	*identifiers;

	a = i + 1;
	b = i + 1;
	while (buffer[b])
	{
		if (ft_is_C(buffer[b]))
			break ;
		b++;
	}
	identifiers = ft_substr(buffer, a, (b - a) + 1);
	check_flags(identifiers);
	check_with(identifiers, args);
	check_percision(identifiers, args);
	if (ft_strchr(identifiers, (int) '%'))
		char_printed = percent_conversion();
	else
		char_printed = p_d_u_conversions_1st(args, identifiers);
	free(identifiers);
	return (char_printed);
}
