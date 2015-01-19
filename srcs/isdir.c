/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:39:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 14:39:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isdir(char *path)
{
	DIR	*temp_dir;

	if (!(temp_dir = readdir(path)))
		return (0);
	closedir(temp_dir);
	return (1);
}
