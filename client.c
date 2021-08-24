#include "ft_minitalk.h"

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

// 기능: 비트로된 한 문자를 보냄, 리턴: void
void	send_msg(int pid, char c)
{
	// 97은 0110 0001
	// SIG1 = 0, SIG2 = 1
	int	i;
	int	tmp;

	i = -1;
	tmp = 0;
	while (++i < 8)
	{
		tmp = c & 1;
		if (tmp == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(1000);
	}
}

int main(int argc, char ** argv)
{
	int i;
	int	pid;

	i = -1;
	pid = 0;
	if (argc != 3)
		printf("Usage: %s PID \n", argv[0]);
	pid = ft_atoi(argv[1]);
	while (argv[2][++i] != '\0')
	{
		send_msg(pid, argv[2][i]);
	}
	return (0);
}

/* 질문
2 client동작을 빠르게 반복 수행할 때 제대로 받아지나
 */