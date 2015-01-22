/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:15:49 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 15:55:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_stdin(char **line)
{
	int	ret;

	if ((ret = get_next_line(0, line)) && ft_strcmp(*line, "exit"))
		return ;
	if (!ret)
		write(1, "exit\n", 5);
	ft_putstr(GOODBYE);
	free(*line);
	exit(0);
}
