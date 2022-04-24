#include "minishell.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	sign;
	int	max;

	max = 19;
	sign = 1;
	i = 0;
	x = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (!max--)
			return ((1 + sign) / (-2));
		x = x * 10 + str[i] - '0';
		i++;
	}
	return (x * sign);
}