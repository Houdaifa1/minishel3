#ifndef MINISHELL_H
# define    MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

typedef struct echo
{
    char    **argumment;
    struct data *next;
}   t_data;

typedef struct env_var
{
    char *var;
    char *val;
    struct env_var *next;

} t_env;
typedef struct hold
{
    char *input;
    char *temp;

} t_hold;



char	*ft_strdup(const char *s1);
char *ft_strjoinee(char *s1, const char *s2);
int ft_is_valid(char c);
int ft_is_digits(char c);
size_t	ft_strlen(const char *s);
void ft_free_list(t_data *head);
int  parse_line(t_data **data, char *input, t_env *env_var);
char **split_line_to_args(char *input);
char *strsplit_by_pipe(char **str);
int	ft_count_args(char *input);
void	ft_add_node(t_data **head, char **arguments);
t_data *creat_node(char **arguments);
int check_qout(char *input);
void exec_commandes(t_data *commandes, t_env **envp, t_data **data, t_hold **hold_vars);
void    exec_echo(char **commande);
void    ft_putstr(char *str);
void exec_cd(char **commande, t_env *envp);
void exec_pwd(char **commande);
char *print_prompt(t_env *envp);
char *ft_getenv(t_env *envp, char *var);
char	*ft_strjoin(char const *s1, char const *s2, int flag, int size);
int ft_strcmp(char *s1, char *s2);
t_env   *env_to_list(char **envp);
t_env *ft_one_node(char *envp);
char *grep_env_value(char *envp, int i);
void ft_free_list2(t_env *head);
void exec_export(char **commande, t_env **envp);
void exec_env(char **commande, t_env *envp);
void ft_print_env(t_env *envp);
t_env *ft_one_node2(char *envp);
int ft_update_val(t_env **envp, char *var, char *val);
void exec_unset(char **commande, t_env **envp);
void exec_exit(char **commande, t_env **envp, t_data **data, t_hold **hold_vars);
int ft_isalpha(int c, int i);
char *remove_plus(char *var);
int ft_contain_plus(char *commande);
int check_argument(char *commande);
int ft_strcmp2(char *s1, char *s2);

#endif