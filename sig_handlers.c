#include "minishell.h"
#include <stdlib.h>
#include <string.h>

// Handler for ctrl+c signal
void	handler_ctrl_c(int val)
{
	val = ft_strlen(rl_line_buffer);
	if (ft_strlen(rl_line_buffer) == 0)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else 
	{
		free(rl_line_buffer);
		rl_line_buffer = malloc(val);
		memset(rl_line_buffer, ' ', val);
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 11);
		rl_redisplay();
	}
}
void	handler_ctrl_z(int val)
{
	(void)val;
	// write(1, "1", 1);
	// char buf;

	// val = read(0, &buf, 1);
	// if (val)
}
// Handler for ctrl+d (EOF)
void	handler_ctrl_d()
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit \n", 1);
	exit(0);
}