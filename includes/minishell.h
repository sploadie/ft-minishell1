/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:12:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/19 16:30:23 by tgauvrit         ###   ########.fr       */
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

# define INPUT_MAX_ARGS 200
# define ESCAPE_CHARS " \t"

typedef struct			s_env_key
{
	char				*key;
	char				*val;
	struct s_env_key	*next;
}						t_env_key;

typedef struct			s_args
{
	char				*str;
	char				**args;
}						t_args;

typedef t_env_key		**t_env;

void					shell_perror(char *s);
void					*shell_pwarning(char *str);
void					ft_sort_string_array(char **string_array, int size);
void					ft_putfourstr(char *s1, char *s2, char *s3, char *s4);

int						isdir(char *path);

t_env					init_shell_env(void);
t_env_key				*gen_env_key(char *key, char *val, t_env_key *next);
char					*key_key_str(char *env_str);
char					*key_val_str(char *env_str);

t_env_key				*fetch_env_key(t_env env, char *key_str);
char					*fetch_key_val(t_env env, char *key_str);
void					print_env(t_env env);
size_t					env_key_count(t_env env);

t_args					*parse_input_args(char *input, int isalloc);

char					*get_exec_path(t_env env, char *cmd);
int						exec_with_env(char *path, char **args, t_env env);

#endif
