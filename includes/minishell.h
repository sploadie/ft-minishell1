/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:12:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/23 12:01:04 by tgauvrit         ###   ########.fr       */
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
# include "get_next_line.h"

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
# define WELCOME "\nWelcome to sploadieShell.\nIs it time to play?\n"
# define GOODBYE "Until next time, sir.\n\n"
# define PROMPT "\n$pl > "
# define QUOTE_PROMPT "\" > "
# define RET_PROMPT "sploadieShell: "

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
	size_t				arg_count;
}						t_args;

/*
** After init, t_env should never be called except as '*env'.
*/

typedef t_env_key		**t_env;

typedef void			(t_spl_func)(t_args *args, t_env env);

void					shell_perror(char *s);
void					*shell_pwarning(char *s1, char *s2);
void					shell_psignal(char *s1, int signum, char *s2, char *signame);
void					handle_sigint(int sig);
void					interpret_status(int status);

void					read_stdin(t_env env, char **line);
void					ft_sort_string_array(char **string_array, int size);
void					ft_strjoinfree(char **line, char *add);
void					ft_putfourstr(char *s1, char *s2, char *s3, char *s4);

t_spl_func				*get_spl_function(char *str);
void					sploadie_cd(t_args *args, t_env env);
void					sploadie_setenv(t_args *args, t_env env);
void					sploadie_unsetenv(t_args *args, t_env env);
void					sploadie_env(t_args *args, t_env env);

int						isdir(char *path);

t_env					init_shell_env(void);
char					*key_key_str(char *env_str);
char					*key_val_str(char *env_str);

t_env_key				*gen_env_key(char *key, char *val, t_env_key *next);
void					add_env_key(t_env env, char *neokey, char *neoval);
int						del_env_key(t_env env, char *del_key);

t_env_key				*fetch_env_key(t_env env, char *key_str);
char					*fetch_key_val(t_env env, char *key_str);
void					print_env(t_env env);
size_t					env_key_count(t_env env);

t_args					*parse_input_args(t_env env, char *input, int isalloc);
void					del_input_args(t_args **args);

char					*get_exec_path(t_env env, char *cmd);
int						fork_exec_with_env(char *path, char **args, t_env env, int status);

char					*append_quote(t_env env, char *str);

#endif
