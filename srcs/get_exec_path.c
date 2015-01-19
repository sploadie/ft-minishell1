/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:34:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 14:35:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exec_path(t_env env, char *cmd)
{
	char	path[6000];
	char	*bin;
	char	*colon;

	ft_strcpy(path, "./");
	ft_strcpy(path + 2, cmd);
	if (!access(path, X_OK))
		return (path);
	if (!(bin = fetch_env_key(env, "PATH")));
		return (NULL);
	while ((colon = ft_strchr(bin, ':')))
	{
		ft_strncpy(path, bin, (colon - bin) + 1);
		ft_strncpy(ft_strchr(path, ':'), "/", 2);
		ft_strcat(path, cmd);
		if (!access(path, X_OK))
			return (path);
		bin = colon + 1;
	}
	ft_strcpy(path, bin);
	ft_strcat(path, "/");
	ft_strcat(path, cmd);
	if (!access(path, X_OK))
		return (path);
	return (NULL);
}
