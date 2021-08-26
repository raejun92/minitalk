#include "ft_minitalk.h"

t_character g_character;

void	zero()
{
	g_character.n++;
}

void	one()
{
	g_character.c = g_character.c | (1 << g_character.n); // 1을 n번 left shift해서 c와 합침
	g_character.n++;
}

int main(void)
{
	g_character.c = 0;
	g_character.n = 0;
	printf("PID: %d\n", getpid());
	// 1, 0 올 때 동작
	signal(SIGUSR1, zero);
	signal(SIGUSR2, one);
	while (1)
	{
		if (g_character.n >= 8)
		{
			write(1, &g_character.c, 1);
			g_character.c = 0;
			g_character.n = 0;
		}
		pause();
	}
}