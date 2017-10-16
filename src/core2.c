#include "corewar_vm_validation.h"


int ft_create_int(unsigned char *magic)
{
	/*
	 * Перевод меджика в инт.
	 */
	unsigned int n;
	
	n = 0;
	n = (unsigned char)magic[0] << 24 | (unsigned char)magic[1] << 16 |
	    (unsigned char)magic[2] << 8 | (unsigned char)magic[3];
	return (n);
}