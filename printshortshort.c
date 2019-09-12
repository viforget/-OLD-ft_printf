#include "includes/ft_printf.h"

void	printshortshort2(char *st, unsigned int d, unsigned int neg, unsigned int base, short short n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * d + neg + 1)))
		return ;
	str[d + neg] = 0;
	str[0] = '-';
	while (d + neg > neg)
	{
		str[d + neg - 1] = st[(n % base * -1)];
		d--;
		n /= base;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

void	printshortshort(short short n, char *st, unsigned int base)
{
	unsigned int		neg;
	short short			nb;
	unsigned int		d;

	d = 0;
	neg = 1;
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 0)
	{
		neg = 0;
		n *= -1;
	}
	nb = n;
	while (nb != 0)
	{
		d++;
		nb /= base;
	}
	printshortshort2(st, d, neg, base, n);
}
