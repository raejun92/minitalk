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

/* ft_utils.c */
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);

#endif