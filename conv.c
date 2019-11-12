/*
** EPITECH PROJECT, 2017
**conv 
** File description:
** conv_int_in_char*
*/

#include "include/my.h"

int	alloc(int num)
{
	int	len = 1;

	if (num < 0) {
		num *= -1;
		len += 1;
	}
	while (num > 9)
	{
		num /= 10;
		len += 1;
	}
	return (len);
}

char	*conv(int num, int len)
{
	char	*str = malloc(sizeof(char) * len + 1);
	int	cn = len - 1;
	int	sign = 0;

	if (num < 0) {
		num *= -1;
		str[0] = '-';
		cn -= 1;
		sign = 1;
	}
	str[len - 1] = num  % 10 + '0';
	while (cn > 0) {
		num /= 10;
		if (sign == 0)
			cn -= 1;
		str[cn] = num % 10 + '0';
		if (sign == 1)
			cn -= 1;
	}
	str[len] = '\0';
	return (str);
}
