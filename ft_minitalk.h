#ifndef FT_MINITALK_H
# define FT_MINITALK_H

#include <stdio.h> // 지워
# include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_node {
	struct s_node	*next;
	int				data;
}t_node;

typedef struct s_list {
	t_node	*head;
	int		count;
}t_list;

/* client.c */
int	ft_atoi(const char *str);
void	send_msg(char *str, char c);

/* server.c */


#endif