/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sploadie_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 10:39:08 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/23 16:00:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sploadie_unsetenv(t_args *args, t_env env)
{
	(void)env;
	if (args->arg_count != 2)
		return ((void)shell_pwarning(args->args[0],
		": incorrect number of arguments (1)"));
	if (!del_env_key(env, args->args[1]))
		return ((void)shell_pwarning(args->args[1],
		": key not found"));
}
