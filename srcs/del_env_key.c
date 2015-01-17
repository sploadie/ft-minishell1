/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:57:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/17 18:39:49 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_key(t_env_key **dead_key)
{
	t_env_key	*temp_key;

	temp_key = *dead_key;
	*dead_key = (*dead_key)->next;
	free(temp_key->key);
	free(temp_key->val);
	free(temp_key);
}

void	del_env_key(t_env env, char *del_key)
{
	if (!*env)
		return ;
	else if (!ft_strcmp((*env)->key, del_key))
		free_key(env);
	else if (ft_strcmp((*env)->key, del_key) < 0)
		del_env_key(&((*env)->next), del_key);
}
