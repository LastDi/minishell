#include "../minishell.h"
#include <stdio.h>

void	tmp_changer(t_shell *shell)
{
	shell->tmp_split_p = 0;
	shell->tmp_split_on_off = 1;
}

void	malloc_part(t_shell *shell, int i)
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

void	malloc_for_pipe_flags(char *str, t_shell *shell, int i, int j)
{
	char	**str1;
  
	memor_part(shell, 111);
	str1 = ft_split_shell(str, ';', -1, shell);
	memor_part(shell, 222);
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

void	create_pipe_matrix(t_shell *shell)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	shell->tmp_split_on_off = 0;
	while (i < shell->func_count)
	{
		j = 0;
		k = shell->start_flag_prog[i];
		while (j < shell->count_flag_prog[i])
		{
			shell->flags_for_prog[i][j] = shell->flags[k];
			j++;
			k++;
		}
		i++;
	}
}

void	free_split_str(char **str, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		free(str[i]);
	free(str);
}

void	work_with_pipes(t_shell *shell, t_com *com, t_list **evl, char **str1)
{
	// int		i;

	// i = -1;
	printf("f count %d\n", shell->func_count);
	/* while (++i < shell->func_count)
	{
		shell->str = ft_split_shell(str1[i], '|', -1, shell);
		shell->pipes[i].pipe_count = shell->pipe_count;
		if (!fd_redirect(shell) && !shell->error)
		{
			restructuring(shell, com);
			shell->error_code = timur(shell->env, com, evl);
		}
		free_split_str(shell->str, shell->pipe_count);
	} */
	(void)evl;
	(void)com;
	free_split_str(str1, shell->func_count);
}

void	minishell(t_shell *shell, t_com *com, t_list **evl)
{
	char	*str;
	char	**str1;

	shell->error = 0;
	shell->free = 0;
	str = readline("minishell> ");
	if (str == NULL)
		handler_ctrl_d();
	if (ft_strncmp(str, "\0", 1) != 0)
		add_history(str);
	set_flag(str, shell);

	if (!preparser(str) && !shell->error)
	{
		str = parser(str, shell);
		shell->error = error_checker(str, shell);
		malloc_for_pipe_flags(str, shell, -1, 0);
		str1 = ft_split_shell(str, ';', -1, shell);
		create_pipe_matrix(shell);
		work_with_pipes(shell, com, evl, str1);
		(void)evl;
		(void)com;
		(void)str1;
	}
	free(str);
}
