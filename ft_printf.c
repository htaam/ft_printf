/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:55:31 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/29 16:14:48 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* global variable declaration */
t_flags	g_flags;

static int	flags_reset(void)
{
	g_flags.type = 0;
	g_flags.with = 0;
	g_flags.minus = 0;
	g_flags.zero = 0;
	g_flags.dot = 0;
	g_flags.percision = 0;
	g_flags.negative = 0;
	if (g_flags.flags)
		ft_memdel((void **)&g_flags.flags);
	return (1);
}

static int	ft_treat_buffer(const char *buffer, va_list args)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	while (buffer[i])
	{
		flags_reset();
		if (buffer[i] == '%')
		{
			char_count = char_count + ft_determinations(args, i, buffer);
			while ((i++) + 1)
			{
				if (ft_is_C(buffer[i]))
				{
					i++;
					break ;
				}
			}
		}
		if (buffer[i] && buffer[i] != '%')
			char_count = char_count + print_n_char(1, buffer[i++]);
	}
	return (char_count * flags_reset());
}

int	ft_printf(const char *input, ...)
{
	char const	*buffer;
	int			char_count;
	va_list		args;

	buffer = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	char_count = ft_treat_buffer(buffer, args);
	va_end(args);
	free((char *)buffer);
	return (char_count);
}
