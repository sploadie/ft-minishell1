/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_with_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:30:19 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 14:30:55 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	env_key_str_len(t_env env)
{
	if (*env)
		return (1 + ft_strlen((*env)->key) + ft_strlen((*env)->val) + env_key_count(&((*env)->next)));
	return (0);
}

void	gen_env_str(t_env env, char *env_s)
{
	if (!*env)
		return ;
	ft_strcpy(env_s, (*env)->key);
	env_s = ft_strchr(env_s, '\0');
	*(env_s++) = '=';
	ft_strcpy(env_s, (*env)->val);
	gen_env_str(&((*env)->next), ft_strchr(env_s, '\0') + 1);
}

void	gen_env_str_ptrs(char **env_p, char *env_s, size_t key_total)
{
	if (!key_total)
		return ((void)(*env_p = NULL));
	*env_p = env_s;
	gen_env_str_ptrs(env_p + 1, ft_strchr(env_s, '\0') + 1, key_total - 1);
}

int		exec_with_env(char *path, char **args, t_env env)
{
	size_t	key_total;
	char	*env_p[(key_total = env_key_count(env))];
	char	env_str[env_key_str_len(env) + 1];

	ft_bzero(env_s, env_str_size);
	gen_env_str(env, env_str);
	gen_env_str_ptrs(env_p, env_str, key_total);
	return (execve(path, args, env_p));
}
