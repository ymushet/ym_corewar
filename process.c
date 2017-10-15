#include "corewar_vm_validation.h"

t_process *ft_malloc_process(t_player *player)
{
	t_process *new;
	
	int i;
	
	i = 0;
	new = malloc(sizeof(t_process));
	while (i < 16)
		new->regs[i++] = 0;
	new->regs[0] = player->number * -1;
	new->cary = 0;
	new->exec_cycle = -1;
	new->func = NULL;
	new->number = player->number;
	new->mem_addres = -1;
	new->dell = 0;
	new->next = NULL;
	return (new);
}

void ft_add2head_process(t_process **head, t_process *add)
{
	t_process *h;
	
	h = *head;
	add->next = h;
	*head = add;
}

t_process *ft_create_proceses(t_player *player)
{
	t_player *p;
	t_process *head;
	t_process *h;
	
	h = NULL;
	head = ft_malloc_process(player);
	player = player->next;
	p = player;
	while (p != NULL)
	{
		h = ft_malloc_process(p);
		ft_add2head_process(&head, h);
		p = p->next;
	}
	return (head);
}

void    ft_kill_processes(t_process **head)
{
	t_process *h;
	t_process *prev;
	
	h = *head;
	prev = NULL;
	while (h != NULL && h->dell == 1)
	{
		*head = h->next;
		free(h);
		h = *head;
	}
	while (h != NULL)
	{
		while (h != NULL && h->dell != 1)
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


void    ft_set_mem_index(t_process *process)
{
	t_process *p;
	int mod;
	int n;
	
	n = 0;
	p = process;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	p = process;
	mod = MEM_SIZE / n;
	while (p != NULL)
	{
		p->mem_addres = (p->number - 1) * mod;
		p = p->next;
	}
}
//int main()
//{
//	t_process *p;
//
//	t_player  *c1;
//	t_player  *c2;
//	t_player  *c3;
//	t_player  *c4;
//
//	c1 = ft_malloc_player(1);
//	c2 = ft_malloc_player(2);
//	c3 = ft_malloc_player(3);
//	c4 = ft_malloc_player(4);
//	c1->next = c2; c2->next = c3; c3->next = c4; c4->next = NULL;
//	p = ft_create_proceses(c1);
//	p->next->dell = 0;
//	ft_kill_processes(&p);
//	printf("%p\n", p);
//	return (0);
//}