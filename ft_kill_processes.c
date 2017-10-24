#include "corewar.h"

void    ft_kill_processes(void)
{
	t_process *h;
	t_process *prev;

	h =  g_dt.process_g;
	prev = NULL;
//	while (h != NULL && h->alive == 0)
//	{
//		*h = h->next;
//		free(h);
//		h = *head;
//	}
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