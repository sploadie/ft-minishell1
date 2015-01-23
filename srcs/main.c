/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:13:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/23 12:14:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fork_exec_wrapper(char *path, char **args, t_env env)
{
	int status;

	status = 0;
	fork_exec_with_env(path, args, env, status);
}

int			main(void)
{
	t_env		env;
	char		*str;
	t_args		*args;
	t_spl_func	*spl_function;

	env = init_shell_env();
	signal(SIGINT, handle_sigint);
	ft_putstr(WELCOME);
	str = NULL;
	while (1)
	{
		ft_putstr(PROMPT);
		read_stdin(env, &str);
		if (!*str)
		{
			free(str);
			continue ;
		}
		args = parse_input_args(env, str, 1);
		if ((spl_function = get_spl_function(args->args[0])))
			(*spl_function)(args, env);
		else if ((str = get_exec_path(env, args->args[0])))
		{
			fork_exec_wrapper(str, args->args, env);
		}
		del_input_args(&args);
	}
	shell_perror("END OF MAIN REACHED");
	return (0);
}
