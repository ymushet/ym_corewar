#include "corewar.h"

static 			t_process *ft_malloc_process(t_player *player)
{
	t_process *new;
	int i;
	
	i = 0;
	new = malloc(sizeof(t_process));
	while (i < REG_NUMBER)
		new->regs[i++] = 0;
	i = 0;
	while (i < 4)
		new->args[i++] = 0;
	new->regs[0] = player->number * -1;
	new->cary = 0;
	new->f = NULL;
	new->exec_cycle = 0;
	new->func = NULL;
	new->number = player->number;
	new->mem_addres = player->mem_addr;
	new->alive = 0;
	new->command = 0;
	new->codage_octal = 0;
	new->next = NULL;
	return (new);
}

static void		ft_add2head_process(t_process **head, t_process *add)
{
	t_process *h;
	
	h = *head;
	add->next = h;
	*head = add;
}

t_process		*ft_create_proceses(t_player *player)
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

