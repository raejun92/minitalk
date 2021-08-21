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
void	send_msg(char *str, char c)
{
	// 97은 0110 0001
	// SIG1 = 0, SIG2 = 1
	int	i;
	int	tmp;
	int	pid;

	i = -1;
	pid = ft_atoi(str);
	tmp = 0;
	while (++i < 8)
	{
		tmp = c & 1;
		if (tmp == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		printf("%d\n", tmp);
		c = c >> 1;
		usleep(300);
	}
}

int main(int argc, char ** argv)
{
	int i;

	i = -1;
	if (argc != 3)
		printf("Usage: %s PID \n", argv[0]);
	while (argv[2][++i] != '\0')
	{
		printf("%c\n", argv[2][i]);
		send_msg(argv[1], argv[2][i]);
	}
	return (0);
}

/* 질문
1 server에서 계속 동작중이게 하려면 지금 저렇게 하면 되나
2 server에서 설정한 SIGUSR1, 2가 client에서 되는 이유는 무엇인가
3 채점 중 서버가 재시작 하지 않고 다중 문자열을 수신할 수 있다 -> ./a.out PID 문자열 문자열 가능?
4 -No more of 8 signals to pass 1 characters 신호 8개 이상 1자 전달 불가 ? 
 */