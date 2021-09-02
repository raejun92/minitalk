#include "ft_minitalk.h"

// 기능: 비트로된 한 문자를 보냄, 리턴: void
void	send_msg(int pid, char c)
{
	// a = 97
	// 97은 0110 0001
	// SIG1 = 0, SIG2 = 1
	int	i;
	int	tmp;

	i = -1;
	tmp = 0;
	while (++i < 8)
	{
		tmp = c & 1; // 0인지 1인지 판단
		if (tmp == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1; // 오른쪽으로 비트이동
		usleep(500);
 	}
}

// 기능: pid가 숫자로 들어오는지 확인, 리턴: void
void	check_pid(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!(argv[i] >= '0' && argv[i] <= '9')) {
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

int main(int argc, char ** argv)
{
	int i;
	int	pid;

	i = -1;
	pid = 0;
	if (argc != 3)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	check_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	while (argv[2][++i] != '\0') // 한 문자씩 보냄
	{
		send_msg(pid, argv[2][i]);
	}
	return (0);
}