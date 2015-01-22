/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:30:44 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 17:47:53 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_status(int ret)
{
	char	str[2];

	str[0] = '0' + ret;
	str[1] = '\0';
	shell_pwarning("process exited normally with status ", str);
}

static void	stop_status(int signum)
{
	char	str[3];

	str[2] = '\0';
	str[1] = '0' + (signum % 10);
	str[0] = '0' + ((signum / 10) % 10);
	shell_pwarning("process paused by signal ", str);
}

static void	signal_status(int signum)
{
	char	str[3];

	str[2] = '\0';
	str[1] = '0' + (signum % 10);
	str[0] = '0' + ((signum / 10) % 10);
	shell_pwarning("process terminated by signal ", str);
}

void	interpret_status(int status)
{
	if (WIFEXITED(status))
		exit_status(WEXITSTATUS(status));
	if (WIFSTOPPED(status))
		stop_status(WSTOPSIG(status));
	if (WIFSIGNALED(status))
		signal_status(WTERMSIG(status));
}
