#include "corewar.h"

void    ft_kill_processes(t_process **head)
{
	t_process *h;
	t_process *prev;

	h = *head;
	prev = NULL;
	while (h != NULL && h->alive == 0)
	{
		*head = h->next;
		free(h);
		h = *head;
	}
	while (h != NULL)
	{
		while (h != NULL && h->alive != 0)
		{
			prev = h;
			h = h->next;
		}
		if (h == NULL)
			return ;
		prev->next = h->next;
		free(h);
		h = prev->next;
	}
}