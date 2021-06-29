/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:14:36 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/08 15:14:38 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_d_u_conversions_1st(va_list args, char *identifiers)
{
	int						char_printed;
	unsigned int			aux_u;
	int						aux_i;
	unsigned long long int	aux_p;

	if (ft_strchr(identifiers, (int) 'p'))
	{
		aux_p = va_arg(args, unsigned long long int);
		char_printed = pointer_conversion(aux_p);
	}
	else if (ft_strchr(identifiers, (int) 'd')
		|| ft_strchr(identifiers, (int) 'i'))
	{
		aux_i = va_arg(args, int);
		char_printed = integer_conversion(aux_i);
	}
	else if (ft_strchr(identifiers, (int) 'u'))
	{
		aux_u = va_arg(args, unsigned int);
		char_printed = unsigned_int_conversion(aux_u);
	}
	else
		char_printed = x_X_conversions_2nd(args, identifiers);
	return (char_printed);
}

int	x_X_conversions_2nd(va_list args, char *identifiers)
{
	int				char_printed;
	unsigned int	aux_X;
	unsigned int	aux_x;

	if (ft_strchr(identifiers, (int) 'x'))
	{
		aux_x = va_arg(args, unsigned int);
		char_printed = unsigned_hexa_lower_conversion(aux_x);
	}
	else if (ft_strchr(identifiers, (int) 'X'))
	{
		aux_X = va_arg(args, unsigned int);
		char_printed = unsigned_hexa_upper_conversion(aux_X);
	}
	else
		char_printed = s_and_c_conversions_3rd(args, identifiers);
	return (char_printed);
}

int	s_and_c_conversions_3rd(va_list args, char *identifiers)
{
	int		char_printed;
	char	*aux_s;
	int		aux_c;

	if (ft_strchr(identifiers, (int) 's'))
	{
		aux_s = va_arg(args, char *);
		char_printed = string_conversion(aux_s);
	}
	else if (ft_strchr(identifiers, (int) 'c'))
	{
		aux_c = va_arg(args, int);
		char_printed = char_conversion((char)aux_c);
	}
	else
		char_printed = 0;
	return (char_printed);
}
