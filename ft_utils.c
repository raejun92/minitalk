#include "ft_minitalk.h"

static int		ft_intlen(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i = i + 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			i;
	long long	ln;

	ln = (long long)n;
	len = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	i = 0;
	if (ln < 0)
	{
		ln = ln * -1;
		str[i++] = '-';
	}
	while (i <= len)
	{
		str[len] = (ln % 10) + '0';
		ln = ln / 10;
		len--;
	}
	return (str);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}