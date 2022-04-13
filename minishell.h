#ifndef PARSER_H
# define PARSER_H

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
	int		error_cod;
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
	// t_pipes	*pipes;
}				t_shell;

//parser
void    multiple_free(void *s1, void *s2, void *s3, void *s4);
char	*find_key(t_shell *shell, char *str1);
#endif
