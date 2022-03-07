#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	int retorno = ft_printf("%x\n", 2147483647);
	int retornop = printf("%x\n", 2147483647);
	ft_printf("retorno: %d, retorno ok: %d", retorno, retornop);
}
