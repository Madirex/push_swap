#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
		value = value * 10 + (*str++ - '0');
	return (sign * value);
}

void ft_putnbr(int n)
{
    char buffer[11];
    int i;
    int is_negative;
    
    i = 10;
    is_negative = 0;
    if (n < 0)
    {
        is_negative = 1;
        n = -n;
    }
    buffer[10] = '\0';
    if (n == 0)
        buffer[--i] = '0';
    while (n > 0)
    {
        buffer[--i] = (n % 10) + '0';
        n /= 10;
    }
    if (is_negative)
        buffer[--i] = '-';
    while (buffer[i])
        write(1, &buffer[i++], 1);
}