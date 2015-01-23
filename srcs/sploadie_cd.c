/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sploadie_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 10:08:35 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/23 12:15:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sploadie_cd(t_args *args, t_env env)
{
	if (args->arg_count != 2)
		return ((void)shell_pwarning(args->args[0], ": incorrect number of arguments (1)"));
	if (chdir(args->args[1]) == -1)
		return ((void)shell_pwarning(args->args[1], ": invalid directory"));
	add_env_key(env, "PWD", getcwd(NULL, 0));
}
