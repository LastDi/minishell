#include "minishell.h"

char	*arg_tipo_unset(char *arg)
{
	char	*arg_new;
	int		i;

	i = 0;
	arg_new = malloc(1000);
	while (arg[i] && arg[i] != '=')
	{
		arg_new[i] = arg[i];
		i++;
	}
	arg_new[i] = '\0';
	return (arg_new);
}

int	tipo_unset_h_c2(char *arg, char *help)
{
	if (ft_strncmp(help, arg, ft_strlen_sym(help, '=')) == 0
		&& (arg[ft_strlen_sym(help, '=')] == '\0'
			|| arg[ft_strlen_sym(help, '=')] == '='))
	{
		return (1);
	}
	return (0);
}

int	tipo_unset_h_c1_test(char *arg, t_list **evl, char *help, t_list *l1)
{
	if (l1 == *evl
		&& ft_strncmp(help, arg, ft_strlen_sym(help, '=')) == 0
		&& (arg[ft_strlen_sym(help, '=')] == '\0'
			|| arg[ft_strlen_sym(help, '=')] == '='))
	{
		return (1);
	}
	return (0);
}

int	ebannyi_tipo_unset1(char *arg, t_list **l1, t_list **l2, t_list **evl)
{
	if (!ft_strchr(arg, '='))
		return (1);
	*evl = *l2;
	free(*l1);
	return (0);
}

int	ebannyi_tipo_unset2(char *arg, t_list **l1, t_list **l3, t_list **l2)
{
	if (!ft_strchr(arg, '='))
		return (1);
	(*l1)->next = *l3;
	free(*l2);
	return (0);
}