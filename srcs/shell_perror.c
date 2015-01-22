/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 13:54:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 17:59:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_perror(char *str)
{
	ft_putstr_fd("sploadieShell: ERROR: ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	else
		ft_putstr_fd("(Error not provided)", 2);
	ft_putstr_fd("\n\n", 2);
	exit(1);
}

void	*shell_pwarning(char *s1, char *s2)
{
	ft_putstr_fd("sploadieShell: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	else
		ft_putstr_fd("WARNING: ", 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	else
		ft_putstr_fd("(Warning not provided)", 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}
