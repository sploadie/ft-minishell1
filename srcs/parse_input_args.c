/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:36:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 17:11:43 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	end_in_quotes(char *str)
{
	int	in_quotes;

	in_quotes = -1;
	while (*str)
	{
		if (*str == '\"')
			in_quotes *= -1;
		str++;
	}
	if (in_quotes > 0)
		return (1);
	return (0);
}

// static char	*next_arg(char *str)
// {
// 	int	in_quotes;

// 	in_quotes = -1;
// 	while (*str && (!ft_strchr(ESCAPE_CHARS, *str) || in_quotes > 0))
// 	{
// 		if (*str == '\"')
// 			in_quotes *= -1;
// 		str++;
// 	}
// 	while (*str && ft_strchr(ESCAPE_CHARS, *str))
// 		str++;
// 	return (str);
// }

static char	*next_arg(char *str)
{
	str = ft_strchr(str, '\0');
	while (*str && ft_strchr(ESCAPE_CHARS, *str))
		str++;
	return (str);
}

int			arg_count_check(int arg_count)
{
	if (arg_count >= INPUT_MAX_ARGS)
		shell_perror("Maximum arguments surpassed");
	return (arg_count);
}

static char	*clip_arg(char *str, int *done)
{
	char	*start;
	char	*curr;
	int	in_quotes;

	start = str;
	curr = str;
	in_quotes = -1;
	while (*curr)
	{
		while (*str == '\"')
		{
			in_quotes *= -1;
			str++;
		}
		if (in_quotes == -1 && ft_strchr(ESCAPE_CHARS, *str))
			*curr = '\0';
		else
			*(curr++) = *(str++);
	}
	if (!*str)
		*done = 1;
	return (start);
}

t_args		*parse_input_args(char *str, int isalloc)
{
	t_args	*neoargs;
	char	*arg_ptrs[INPUT_MAX_ARGS];
	int		arg_count;
	int		done;

	if (!isalloc)
		str = ft_strdup(str);
	if (end_in_quotes(str))
		return (parse_input_args(append_quote(str), 1));
	neoargs = check_malloc(ft_memalloc(sizeof(t_args)));
	neoargs->str = str;
	arg_count = -1;
	done = 0;
	while (!done, *(str = next_arg(str)))
		arg_ptrs[arg_count_check(++arg_count)] = clip_arg(str++, &not_done);
	arg_ptrs[arg_count_check(++arg_count)] = NULL;
	neoargs->args = ft_memdup(arg_ptrs, sizeof(char *) * arg_count);
	return (neoargs);
}
