/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:24:29 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 14:25:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env env)
{
	if (!*env)
		return ;
	ft_putfourstr((*env)->key, "=", (*env)->val, "\n");
	print_env(&((*env)->next));
}
