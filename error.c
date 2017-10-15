#include "corewar_vm_validation.h"

int ft_error(int code)
{
	code == 1 ? ft_printf("Not valid magic namber\n") : 0;
	code == 2 ? ft_printf("Not valid program name\n") : 0;
	code == 3 ? ft_printf("Not valid comment\n") : 0;
	code == 4 ? ft_printf("Not valid equalizing byte\n") : 0;
	code == 5 ? ft_printf("Not valid program size\n") : 0;
	code == 6 ? ft_printf("Not valid instruction\n") : 0;
	exit(code);
}