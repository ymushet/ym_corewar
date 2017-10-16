#include "corewar_vm_validation.h"
/*
 * typedef struct t_game
 * {
 *      int cycle; //равно j;
 *      int n_processes //количесство живых процессов
 * }
 */
void ft_game_cycle(t_process *process, char map[3]) //нужна еще одна структура, где будут отслеживаться лайвы и все такое
{
	t_process *p;
	int increment;
	int j;
	
	i = CYCLE_TO_DIE;
	while (i != 0 || p != NULL)
	{
		p = process;
		while (p != NULL)
		{
			//логика выполнения каретки.
			p = p->next;
		}
		j++;
		if (j == i)
		{
			i = ft_change_cycle2die(i);
			ft_kill_processes(&process);
		}
		//else if () //если лайвов < NBR_LIVE и
	}
}