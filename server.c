#include "ft_minitalk.h"

void	f(int signum)
{
	printf("%d\n", 0);
}

void	g(int signum)
{
	printf("%d\n", 1);
}

// t_node	*new_node(int data)
// {
// 	t_node *node;
	
// 	node = (t_node *)malloc(sizeof(t_node) * 1);
// 	node->data = data;
// 	return node;
// }

// void			add_node(t_list *list, int data)
// {
// 	t_node *cur;

// 	cur = new_node(data);
// 	cur->next = list->head->next;
// 	list->head->next = cur;
// 	list->count++;
// }

// void	init_list(t_list *list)
// {
// 	list->head = new_node(0);
// 	list->count = 0;
// }

int main(void)
{
	int		i;
	// t_list	list;
	
	// init_list(&list);
	printf("PID: %d\n", getpid());
	// 1, 0 올 때 동작
	signal(SIGUSR1, f);
	signal(SIGUSR2, g);
	i = 0;
	while (++i)
	{
		sleep(1);
	}
}