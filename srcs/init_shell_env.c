/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:56:40 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/17 17:01:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env_key	*parse_env_key(char **env_ptr)
{
	if (*env_ptr == NULL)
		return (NULL);
	return (gen_env_key(key_key_str(*env_ptr),
		key_val_str(*env_ptr),
		parse_env_key(env_ptr + 1)));
}

t_env	init_shell_env(void)
{
	t_env		neoenv;
	t_env_key	*key;

	ft_sort_string_array(environ, -1);
	key = parse_env_key(environ);
	neoenv = &key;
	return (neoenv);
}
