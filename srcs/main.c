/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:13:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 17:58:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int			main(int argc, char **argv, char **envp)
int			main(void)
{
	char	**env_ptr;
	t_env	env;
	char	*str;
	// int		i;
	t_args	*args;

	// ft_putstr("Original environ:\n");
	// env_ptr = environ;
	// while (*env_ptr)
	// {
	// 	ft_putstr(*env_ptr);
	// 	write(1, "\n", 1);
	// 	env_ptr++;
	// }
	//DEBUG ENV START
	ft_putstr("\nSorted environ:\n\n");
	ft_sort_string_array(environ, -1);
	env_ptr = environ;
	while (*env_ptr)
		ft_putendl(*(env_ptr++));
	ft_putstr("\nParsed version:\n\n");
	env = init_shell_env();
	print_env(env);
	//DEBUG ENV END
	// ft_putstr("\nDeleted PWD:\n\n");
	// del_env_key(env, "PWD");
	// print_env(env);

	//START THE REAL STUFF
	signal(SIGINT, handle_sigint);
	ft_putstr(WELCOME);
	str = NULL;
	while (1)
	{
		ft_putstr(PROMPT);
		read_stdin(&str);
		if (!*str)
		{
			free(str);
			continue ;
		}
		//DEBUG PRINT START
		// ft_putstr("\n=-=\n");
		// ft_putstr(str);
		// ft_putstr("EOF\n=-=");
		//DEBUG PRINT END
		args = parse_input_args(str, 1);
		//DEBUG ARG PARSER START
		// ft_putstr("=-=");
		// i = 0;
		// while (args->args[i] != NULL)
			// ft_putfourstr("\n=-", args->args[i++], "-=", NULL);
		// ft_putstr("\n=-=\n");
		if ((str = get_exec_path(env, args->args[0])))
		{
			// ft_putstr("Command caught: ");
			// ft_putendl(str);
			fork_exec_with_env(str, args->args, env);
		}
		//DEBUG ARG PARSER END
		del_input_args(&args);
	}
	shell_perror("END OF MAIN REACHED");
	return (0);
}
