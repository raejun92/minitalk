#ifndef FT_MINITALK_H
# define FT_MINITALK_H

#include <stdio.h> // 지워
# include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_character {
	char	c;
	int		n;
}t_character;

/* client.c */
int	ft_atoi(const char *str);
void	send_msg(int pid, char c);

/* server.c */


#endif