/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 13:54:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/17 14:36:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*shell_perror(char *str)
{
	ft_putendl_fd("Error: ", 2);
	if (str)
		ft_putendl_fd(str, 2);
	else
		ft_putendl_fd("(Error not provided)", 2);
	ft_putendl_fd("\n", 2);
	return (NULL);
}
