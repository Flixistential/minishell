
#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_pwd(void);
int		ft_executebuiltin(t_info *inf);
int		ft_env(char **env);
int		ft_cd(char **cmd, char **env);
char	*ft_findhome(char **env);
int		ft_unset(t_info *inf);
char	**unset_var(t_info *inf, int unset_index);
int		env_finder(char *str, char **env);
int		env_len(char **env);

#endif