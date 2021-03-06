/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_key_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:27:48 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 14:28:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	env_key_count(t_env env)
{
	if (*env)
		return (1 + env_key_count(&((*env)->next)));
	return (0);
}
