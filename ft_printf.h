/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:49:59 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/29 16:01:21 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> // remove later

# ifndef HEXA_LOWER
#  define HEXA_LOWER "0123456789abcdef"
# endif

# ifndef HEXA_UPPER
#  define HEXA_UPPER "0123456789ABCDEF"
# endif

# ifndef DECIMAL
#  define DECIMAL "0123456789"
# endif

# ifndef CONV
#  define CONV "cspdiuxX%"
# endif

# ifndef FLAG
#  define FLAG "-0"
# endif

typedef struct s_flags
{
	char	type;
	int		with;
	char	*flags;
	int		minus;
	int		zero;
	int		dot;
	int		percision;
	int		negative;
}	t_flags;

extern t_flags	g_flags;

int		ft_printf(const char *input, ...);

int		final_output(char *s);
int		print_n_char(int n, char c);

int		percent_conversion(void);
int		char_conversion(char c);
int		string_conversion(char *s);
int		integer_conversion(long long int d);
int		unsigned_int_conversion(unsigned int u);
int		unsigned_hexa_lower_conversion(unsigned int x);
int		unsigned_hexa_upper_conversion(unsigned int X);
int		pointer_conversion(unsigned long long int d);

int		ft_determinations(va_list args, int i, const char *buffer);

int		ft_is_C(char c);
int		ft_is_flag(char c);

int		p_d_u_conversions_1st(va_list args, char *identifiers);
int		x_X_conversions_2nd(va_list args, char *identifiers);
int		s_and_c_conversions_3rd(va_list args, char *identifiers);

void	check_flags(char *identifiers);
void	check_with(char *identifiers, va_list args);
void	check_percision(char *identifiers, va_list args);

#endif
