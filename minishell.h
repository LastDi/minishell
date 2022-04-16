#ifndef MINISHELL_H
# define MINISHELL_H

# include "src/libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include <errno.h>

# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_pipes {
	int		pipe_count;
	int		fd_in;
	int		fd_out;
	int		*flags;
}				t_pipes;

typedef struct s_shell {
	char	**str;
	int		pipe_count;
	int		pipe_count_max;
	int		func_count;
	int		i;
	int		j;
	int		n;
	int		error;
	int		flags_count;
	int		longs;
	int		error_code;
	int		preflag;
	int		lenght;
	int		*flags;
	int		**flags_for_prog;
	int		tmp_split_p;
	int		tmp_split_on_off;
	int		*start_flag_prog;
	int		*count_flag_prog;
	int		cycle;
	char	tmp_split;
	int		tmp_split2;
	int		free;
	char	**env;
	t_pipes	*pipes;
}				t_shell;

typedef struct command
{
	char			*name;
	char			**flags;
	struct command	*next;
	int				fd_in;
	int				fd_out;
	char			*path;
}				t_com;

void	minishell(t_shell *shell, t_com *com, t_list **evl);

//parser
char	*parser(char *s, t_shell *shell);
int		preparser(char *str);
void    multiple_free(void *s1, void *s2, void *s3, void *s4);
char	*find_key(t_shell *shell, char *str1);

//signals
void	handler_ctrl_c(int val);
void	handler_ctrl_d();

//errors
int	error_checker(char *str, t_shell *shell);

char	**ft_split_shell(char const *s, char c, int i, t_shell *shell);


// DELETE IT
void show_struct(t_shell *shell, char *s);
void set_point(char *s);


#endif
