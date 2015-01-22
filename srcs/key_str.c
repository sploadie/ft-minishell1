/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:00:21 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 16:48:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	print_original_environ(char **env_ptr)
// {
// 	while (*env_ptr)
// 	{
// 		ft_putstr(*env_ptr);
// 		write(1, "\n", 1);
// 		env_ptr++;
// 	}
// }

char	*key_key_str(char *env_str)
{
	char	*eql_ptr;

	if (!(eql_ptr = ft_strchr(env_str, '=')))
	{
		// print_original_environ(environ);
		shell_perror("Invalid variable in the [environ] standard C global");
	}
	return (ft_strsub(env_str, 0, eql_ptr - env_str));
}

char	*key_val_str(char *env_str)
{
	char	*eql_ptr;

	if (!(eql_ptr = ft_strchr(env_str, '=')))
	{
		// print_original_environ(environ);
		shell_perror("Invalid variable in the [environ] standard C global");
	}
	return (ft_strdup(eql_ptr + 1));
}
