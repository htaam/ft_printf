/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:12:27 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/12 12:12:29 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	final_output(char *s)
{
	if (!s)
		return (0);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	print_n_char(int n, char c)
{
	int	a;

	a = 1;
	while (a++ <= n)
		ft_putchar_fd(c, 1);
	return (n);
}
