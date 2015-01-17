/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:13:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/17 15:19:41 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int			main(int argc, char **argv, char **envp)
int			main(void)
{
	char **env_ptr;

	ft_putstr("Hello World!\n");
	env_ptr = environ;
	while (*env_ptr)
	{
		ft_putstr(*env_ptr);
		ft_putstr("   ->   ");
		ft_putstr(ft_strchr(*env_ptr, '\0') + 1);
		write(1, "\n", 1);
		env_ptr++;
	}
	ft_putstr("\nSorted:\n\n");
	ft_sort_string_array(environ, -1);
	env_ptr = environ;
	while (*env_ptr)
	{
		ft_putstr(*env_ptr);
		ft_putstr("   ->   ");
		ft_putstr(ft_strchr(*env_ptr, '\0') + 1);
		write(1, "\n", 1);
		env_ptr++;
	}
	return (0);
}
