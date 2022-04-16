#include "../minishell.h"

// Handler for ctrl+c signal
void	handler_ctrl_c(int val)
{
	(void)val;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \n", 1);
	rl_on_new_line();
	rl_redisplay();
}

// Handler for ctrl+d (EOF)
void	handler_ctrl_d()
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit \n", 1);
	exit(0);
}