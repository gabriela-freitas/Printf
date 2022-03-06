#include "ft_printf.h"

int main ()
{
	char *str = "*";
	int	retorno;
	void *prt;
	prt = &retorno;

	retorno = ft_printf("This is an empity string: %s\nThis is an address: %p\n", str, prt);
	ft_printf("retorno: %d", retorno);
}
