#include "../minishell.h"
#include <stdio.h>

void	tmp_write(t_shell *shell, char c, int i)
{
		shell->tmp_split = c;
		shell->tmp_split2 = i;
}

void	record_num(int count, t_shell *shell, char c)
{
	if (c == ';')
		shell->func_count = count;
	if (c == '|')
	{
		shell->pipe_count = count;
		if (count > shell->pipe_count_max)
			shell->pipe_count_max = count;
	}
}

void	ft_freesplit_2(char **x)
{
	int	i;

	i = 0;
	printf("malloc error\n");
	while (x[i])
		free(x[i++]);
	free(x);
}

int	ft_splitcounterword_2(char const*s, char c, t_shell *shell)
{
	int		i;
	char	pre;
	int		count;

	pre = c;
	shell->preflag = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		printf("%c %c %d %d %d %d\n", pre, s[i], shell->preflag, shell->flags[i], count, i);
		if (((s[i] != c) || (s[i] == c && !shell->flags[i])) \
		&& pre == c && shell->preflag)
			count++;
		pre = s[i];
		shell->preflag = shell->flags[i];
		i++;
	}
	shell->preflag = 1;
	// show_struct(shell, " 2 counter");
	return (count);
}

int	ft_splitcounterchar_2(char const *s, char c, t_shell *shell)
{
	int	i;

	i = 0;
	while ((s[i] != c && s[i]) || (s[i] == c && \
	!shell->flags[shell->tmp_split2 + i]))
		i++;
	return (i);
}

int	ft_splitwriterword_2(const char *s, char **x, int l, t_shell *shell)
{
	int	h;
	int	count;

	count = ft_splitcounterchar_2 (s, shell->tmp_split, shell);
	x[l] = (char *)malloc(count + 1);
	if (x[l] == 0)
		ft_freesplit_2 (x);
	if (x[l] == 0)
		return (0);
	h = 0;
	while ((s[h] && s[h] != shell->tmp_split) || (s[h] == \
	shell->tmp_split && !shell->flags[shell->tmp_split2 + h]))
	{
		x[l][h] = s[h];
		h++;
	}
	if (shell->tmp_split_on_off)
	{
		shell->start_flag_prog[shell->tmp_split_p] = shell->tmp_split2;
		shell->count_flag_prog[shell->tmp_split_p] = h;
		shell->tmp_split_p++;
	}
	x[l][h] = 0;
	l++;
	return (l);
}

char	**ft_split_shell(char const *s, char c, int i, t_shell *shell)
{
	int		count;
	int		l;
	char	**x;
	char	pre;

	show_struct(shell, "1");
	// set_point("1");
	pre = c;
	l = 0;
	if (!s)
		return (0);
	count = ft_splitcounterword_2(s, c, shell);
	record_num(count, shell, c);
	// set_point("2");
	x = (char **) malloc(sizeof (char *) * (count + 1));
	if (!x)
		return (0);
	x[count] = 0;
	// set_point("3");
	while (s[++i])
	{
		// set_point("4");
		tmp_write(shell, c, i);
		if (((s[i] != c) || (s[i] != c && !shell->flags[i])) \
		&& pre == c && shell->preflag)
			l = ft_splitwriterword_2(s + i, x, l, shell);
		shell->preflag = shell->flags[i];
		pre = s[i];
	}
	// set_point("5");
	return (x);
}