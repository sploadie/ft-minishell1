/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:29:08 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/22 11:51:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_quote(char *str)
{
	char	*str_add;

	str_add = NULL;
	ft_putstr(QUOTE_PROMPT);
	read_stdin(&str_add);
	ft_strjoinfree(&str, "\n");
	ft_strjoinfree(&str, str_add);
	free(str_add);
	return (str);
}
