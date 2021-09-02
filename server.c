#include "ft_minitalk.h"

t_character g_character;

// 기능: signal SIGUSR1일 때 이벤트 함수, 리턴: void
void	zero()
{
	g_character.n++;
}

// 기능: signal SIGUSR2일 때 이벤트 함수, 리턴: void
void	one()
{
	g_character.c = g_character.c | (1 << g_character.n); // 1을 n번 left shift해서 c와 합침
	g_character.n++;
}

// 기능: PID 번호 출력, 리턴: void
void	print_pid()
{
	int		pid;
	char	*num_str;

	pid = getpid();
	write(1, "PID: ", 5);
	num_str = ft_itoa(pid);
	write(1, num_str, ft_strlen(num_str));
	write(1, "\n", 1);
}

int main(void)
{
	g_character.c = 0;
	g_character.n = 0;
	print_pid();
	// 1, 0 올 때 동작
	signal(SIGUSR1, zero);
	signal(SIGUSR2, one);
	while (1)
	{
		if (g_character.n == 8)
		{
			write(1, &g_character.c, 1);
			g_character.c = 0;
			g_character.n = 0;
		}
		pause();
	}
}