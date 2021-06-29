/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_conversion_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:46:40 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/08 16:46:45 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_C(char c)
{
	int	a;

	a = 0;
	while (CONV[a])
	{
		if (ft_strchr(CONV, (int)c))
		{
			return (1);
		}
		a++;
	}
	return (0);
}

int	ft_is_flag(char c)
{
	int	a;

	a = 0;
	while (FLAG[a])
	{
		if (ft_strchr(FLAG, (int)c))
			return (1);
		a++;
	}
	return (0);
}

void	check_flags(char *identifiers)
{
	int	a;

	a = 0;
	while (ft_is_flag(identifiers[a]))
	{
		a++;
	}
	if (a)
	{
		g_flags.flags = ft_substr(identifiers, 0, a);
		if (ft_strchr(g_flags.flags, (int) '-'))
			g_flags.minus = 1;
		else if (ft_strchr(g_flags.flags, (int) '0'))
			g_flags.zero = 1;
	}
}

void	check_with(char *identifiers, va_list args)
{
	int		a;
	int		b;
	char	*with;

	a = 0;
	while (ft_is_flag(identifiers[a]))
		a++;
	b = a;
	while (identifiers[b] != '.' && !(ft_is_C(identifiers[b])))
		b++;
	if (b > a)
	{
		with = ft_substr(identifiers, a, b - a);
		if (ft_strchr(with, (int) '*'))
		{
			g_flags.with = va_arg(args, int);
			if (g_flags.with < 0)
				g_flags.minus = 1;
			if (g_flags.with < 0)
				g_flags.with = g_flags.with * (-1);
		}
		else
			g_flags.with = ft_atoi(with);
		ft_memdel((void **)&with);
	}
}

void	check_percision(char *iden, va_list args)
{
	int		a;
	char	*percision;

	a = 0;
	while (iden[a])
	{
		if (iden[a] == '.')
		{
			g_flags.dot = 1;
			break ;
		}
		a++;
	}
	if (ft_strlen(iden) > a + 1)
	{
		percision = ft_substr(iden, a + 1, ft_strlen(iden) - a - 1);
		if (ft_strchr(percision, (int) '*'))
			g_flags.percision = va_arg(args, int);
		else
			g_flags.percision = ft_atoi(percision);
		if (percision)
			ft_memdel((void **)&percision);
	}
	if (g_flags.percision < 0)
		g_flags.dot = 0;
}
