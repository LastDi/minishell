#include "../minishell.h"

int	fd_redirect_output_2(t_shell *shell)
{
	char	*str;
	char	*str1;
	char	*str2;

	if (shell->pipes[shell->i].fd_out != -1)
		close(shell->pipes[shell->i].fd_out);
	if (fd_file_exist(shell->str[shell->i], shell->j, 2))
		return (1);
	str = ft_find_file_name(shell->str[shell->i] + shell->j + 2, shell, 0);
	if (!str)
		return (1);
	shell->pipes[shell->i].fd_out = open (str, O_WRONLY \
	| O_CREAT | O_APPEND, 0777);
	if (shell->pipes[shell->i].fd_out < 0)
		printf("syntax error near unexpected token newline\n");
	if (shell->pipes[shell->i].fd_out < 0)
		return (0);
	str1 = ft_substr(shell->str[shell->i], 0, shell->j);
	str2 = ft_strdup(shell->str[shell->i] + shell->n + 2);
	free(shell->str[shell->i]);
	shell->str[shell->i] = ft_strjoin(str1, str2);
	multiple_free(str1, str2, NULL, NULL);
	return (0);
}

int	fd_redirect_output_1(t_shell *shell)
{
	char	*str;
	char	*str1;
	char	*str2;

	if (shell->pipes[shell->i].fd_out != -1)
		close(shell->pipes[shell->i].fd_out);
	if (fd_file_exist(shell->str[shell->i], shell->j, 1))
		return (1);
	str = ft_find_file_name(shell->str[shell->i] + shell->j + 1, shell, 0);
	if (!str)
		return (1);
	shell->pipes[shell->i].fd_out = open (str, O_WRONLY | O_CREAT | \
	O_TRUNC, 0777);
	if (shell->pipes[shell->i].fd_out < 0)
		printf("syntax error near unexpected token newline\n");
	if (shell->pipes[shell->i].fd_out < 0)
		return (1);
	str1 = ft_substr(shell->str[shell->i], 0, shell->j);
	str2 = ft_strdup(shell->str[shell->i] + shell->n + 1);
	free(shell->str[shell->i]);
	shell->str[shell->i] = ft_strjoin(str1, str2);
	multiple_free(str, str1, str2, NULL);
	return (0);
}

int	fd_redirect_output(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (i < shell->pipe_count)
	{
		shell->pipes[i].fd_out = -1;
		j = 0;
		while (shell->str[i][j])
		{
			shell->i = i;
			shell->j = j;
			if (shell->str[i][j] == '>' && shell->str[i][j + 1] \
			&& shell->str[i][j + 1] == '>' && fd_redirect_output_2(shell))
				return (1);
			else if (shell->str[i][j] == '>' && fd_redirect_output_1(shell))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}