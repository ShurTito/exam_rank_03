#include <stdarg.h>
#include <unistd.h>

void	ft_putstr(char *str, int *len)
{
	if(!str)
		str = "(null)";
	while(*str)
		*len += write(1, str++, 1);
}

void ft_put_digit(long long int nbr, int base, int *len)
{
	char *hexa = "0123456789abcdef";

	if( nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if(nbr >= base)
		ft_put_digit((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

int ft_printf(const char *str, ...)
{
	va_list arg;
	int len = 0;

	va_start(arg, str);
	while(*str)
	{
		if((*str == '%') && ((*(str + 1) == 's') || (*(str + 1) == 'd') || (*(str + 1) == 'x')))
		{
			str++;
			if (*str == 's')
				ft_putstr(va_arg(arg, char *), &len);
			else if (*str == 'd')
				ft_put_digit((long long int)va_arg(arg, int), 10, &len);
			else if (*str == 'x')
				ft_put_digit((long long int)va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	
	va_end(arg);
	return(len);
}
/*
int main(void)
{
	ft_printf("hola\n");
    ft_printf("%s\n","hola2");
    ft_printf("%d\n",-42);

}
*/
