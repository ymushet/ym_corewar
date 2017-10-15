#include "corewar_vm_validation.h"

static int ft_power(int n, int p)
{
	if (p == 0)
		return (1);
	while (p != 1)
	{
		n *= n;
		p--;
	}
	return (n);
}

static int     ft_get_nb(char ch)
{
	char *search = "0123456789abcdef\0";
	
	ch = ft_tolower(ch);
	int i = 0;
	while (search[i])
	{
		if (ch == search[i])
			break ;
		i++;
	}
	return (i);
}

int ft_atoi_base(char *str, int base)
{
	int res;
	int i;
	int j;
	int tmp;
	
	j = 0;
	res = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		tmp = ft_get_nb(str[i]);
		res = res + (tmp * ft_power(base, j));
		i--;
		j++;
	}
	return (res);
}