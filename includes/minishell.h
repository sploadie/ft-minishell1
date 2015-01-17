/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:12:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/17 16:59:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libft.h"
# include "filedir.h"

extern char				**environ;

/*
** Permitted functions:
** opendir
** readdir
** closedir
** malloc
** free
** exit
** getcwd
** chdir
** fork
** stat
** lstat
** fstat
** open
** close
** read
** write
** execve
** access
** wait
** waitpid
** wait3
** wait4
** signal
** kill
*/

typedef struct			s_env_key
{
	char				*key;
	char				*val;
	struct s_env_key	*next;
}						t_env_key;

typedef t_env_key		**t_env;

void					*shell_perror(char *s);
void					ft_sort_string_array(char **string_array, int size);

t_env					init_shell_env(void);

#endif
