/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sploadie_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 10:26:50 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/23 16:00:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sploadie_setenv(t_args *args, t_env env)
{
	if (args->arg_count != 3)
		return ((void)shell_pwarning(args->args[0],
		": incorrect number of arguments (2)"));
	add_env_key(env, args->args[1], ft_strdup(args->args[2]));
}
