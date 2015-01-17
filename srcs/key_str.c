/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:00:21 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/17 17:01:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*key_key_str(char *env_str)
{
	char	*str;
	size_t	len;

	if (!(str = ft_strchr(env_str, '=')))
		shell_perror("Invalid variable in the environ");
	len = env_str - str;
	str = check_malloc(malloc(sizeof(char) * (len + 1)));
	strncpy(str, env_str, len);
	str[len] = '\0'
	return (str);
}

char	*key_val_str(char *env_str)
{
	char	*str;

	if (!(str = ft_strchr(env_str, '=')))
		shell_perror("Invalid variable in the environ");
	return (ft_strdup(str + 1));
}
