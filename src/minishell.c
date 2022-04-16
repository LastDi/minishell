#include "../minishell.h"

void	tmp_changer(t_shell *shell)
{
	shell->tmp_split_p = 0;
	shell->tmp_split_on_off = 1;
}

void	memor_part(t_shell *shell, int i)
{
	if (i == 111)
	{
		shell->pipe_count_max = 0;
		shell->tmp_split_on_off = 0;
		shell->free = 1;
	}
	if (i == 222)
	{
		if (shell->pipes != NULL)
			free(shell->pipes);
		if (shell->flags_for_prog != NULL)
			free(shell->flags_for_prog);
		if (shell->start_flag_prog != NULL)
			free(shell->start_flag_prog);
		if (shell->count_flag_prog != NULL)
			free(shell->count_flag_prog);
		shell->pipes = malloc(sizeof(t_pipes) * shell->func_count);
		shell->flags_for_prog = malloc(sizeof(void **) * shell->func_count);
		shell->start_flag_prog = malloc(sizeof(int) * shell->func_count);
		shell->count_flag_prog = malloc(sizeof(int) * shell->func_count);
	}
}

void	memor_for_pipe_flags(char *str, t_shell *shell, int i, int j)
{
	char	**str1;

	set_point("-1");
	memor_part(shell, 111);
	str1 = ft_split_shell(str, ';', -1, shell);
	set_point("6");
	memor_part(shell, 222);
	set_point("7");
	while (++i < shell->func_count)
		shell->flags_for_prog[i] = malloc(sizeof(int) \
		* shell->flags_count + shell->longs + 1);
	i = -1;
	while (++i < shell->func_count)
	{
		shell->str = ft_split_shell(str1[i], '|', -1, shell);
		j = -1;
		while (j++ < shell->pipe_count)
			free(shell->str[j]);
		free(shell->str);
	}
	free(shell->pipes);
	shell->pipes = malloc(sizeof(t_pipes) * shell->pipe_count_max + 20);
	i = -1;
	while (++i < shell->func_count)
		free(str1[i]);
	free(str1);
	tmp_changer(shell);
}

void	set_flag(char *str, t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->flags_count != -1)
		free(shell->flags);
	while (str[i])
		i++;
	shell->flags_count = i;
	shell->flags = malloc(sizeof(int) * i + shell->longs);
	i = 0;
	while (i < shell->flags_count)
	{
		shell->flags[i] = 0;
		i++;
	}
}

void	minishell(t_shell *shell, t_com *com, t_list **evl)
{
	char	*str;
	char	**str1;

	shell->error = 0;
	shell->free = 0;
	str = readline("minishell> ");
	set_point("-5");
	if (str == NULL)
		handler_ctrl_d();
	set_point("-4");
	if (ft_strncmp(str, "\0", 1) != 0)
		add_history(str);
	set_flag(str, shell);
		set_point("-3");

	if (!preparser(str) && !shell->error)
	{
		set_point("-2");
		str = parser(str, shell);
		shell->error = error_checker(str, shell);
		memor_for_pipe_flags(str, shell, -1, 0);
		// str1 = ft_split_shell(str, ';', -1, shell);
		// write_pipe_flags(shell);
		// work_with_pipes(shell, com, evl, str1);
		(void)str1;
		(void)evl;
		(void)com;
	}
	free(str);
}