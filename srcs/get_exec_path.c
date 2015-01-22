/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:34:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 14:51:25 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exec_path(t_env env, char *cmd)
{
	char	path[6000];
	char	*bin;
	char	*colon;

	if (!cmd)
		shell_perror("get_exec_path recieved NULL command string");
	if (!*cmd)
		return (shell_pwarning("not a valid command: ", "(Empty)"));
	if (isdir(cmd))
		return (shell_pwarning("is a directory: ", cmd));
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	if (!(bin = fetch_key_val(env, "PATH")))
		return (NULL);
	while ((colon = ft_strchr(bin, ':')))
	{
		ft_strncpy(path, bin, (colon - bin) + 1);
		ft_strncpy(ft_strchr(path, ':'), "/", 2);
		ft_strcat(path, cmd);
		if (!access(path, X_OK))
			return (ft_strdup(path));
		// ft_putfourstr("\nFailed path (ret: ", ft_itoa(access(path, X_OK)), "): ", path);//FIXME
		bin = colon + 1;
	}
	ft_strcpy(path, bin);
	ft_strcat(path, "/");
	ft_strcat(path, cmd);
	if (!access(path, X_OK))
		return (ft_strdup(path));
	if (!access(cmd, F_OK))
		shell_pwarning("permission denied: ", cmd);
	else if (ft_strchr(cmd, '/'))
		shell_pwarning("no such file or directory: ", cmd);
	else
		shell_pwarning("command not found: ", cmd);
	// ft_putfourstr("\nFailed path (ret: ", ft_itoa(access(path, X_OK)), "): ", path);//FIXME
	return (NULL);
}
