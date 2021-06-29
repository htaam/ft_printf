#include "ft_printf.h"

static void	unsigned_int_aux_1(int *a, int *b, int *l)
{
	if (g_flags.dot)
		g_flags.zero = 0;
	if (g_flags.percision > *l)
	{
		*a = g_flags.percision - *l;
		*l = g_flags.percision;
	}
	if (g_flags.with > *l)
	{
		*b = g_flags.with - *l;
		if (!g_flags.minus && !g_flags.zero)
			print_n_char(*b, ' ');
		if (!g_flags.minus && g_flags.zero)
			print_n_char(*b, '0');
	}
	if (*a)
		print_n_char(*a, '0');
}

int	unsigned_int_conversion(unsigned int u)
{
	char	*s;
	int		a;
	int		b;
	int		l;

	b = 0;
	a = 0;
	s = ft_itoa_base_unsigned(u, DECIMAL);
	if (u == 0 && g_flags.dot && g_flags.percision == 0)
		ft_bzero(s, ft_strlen(s));
	l = ft_strlen(s);
	unsigned_int_aux_1(&a, &b, &l);
	a = a + final_output(s);
	if (g_flags.minus && g_flags.with > l)
		print_n_char(b, ' ');
	free(s);
	return (a + b);
}
