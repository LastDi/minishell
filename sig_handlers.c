/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:37:44 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:37:46 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Handler for ctrl+c signal
void	handler_ctrl_c(int val)
{
	val = ft_strlen(rl_line_buffer);
	if (val == 0)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (val && ft_strncmp(rl_line_buffer, "cat", 3))
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

// Handler for ctrl+\ signal
void	handler_ctrl_backslash(int val)
{
	val = ft_strlen(rl_line_buffer);
	if (val > 0 && !(ft_strncmp(rl_line_buffer, "cat", 3) || ft_strncmp(rl_line_buffer, "head", 4)
	|| ft_strncmp(rl_line_buffer, "tail", 4)))
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("\nexit \n", 1);
	}
	else if ((ft_strncmp(rl_line_buffer, "cat", 3) || ft_strncmp(rl_line_buffer, "head", 4
	|| ft_strncmp(rl_line_buffer, "tail", 4))))
	{
		ft_putstr_fd("Quit (core dumped)\n", 1);
		exit(0);
	}
	else 
	{
		rl_on_new_line();
		rl_replace_line("", 11);
		rl_redisplay();
	}
}

// Handler for ctrl+d (EOF)
/* void	handler_ctrl_d()
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit \n", 1);
	exit(0);
} */

void	handler_ctrl_d()
{
	rl_redisplay();
	ft_putstr_fd("exit \n", 1);
	exit(0);
}
