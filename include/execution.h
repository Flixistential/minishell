/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:49:05 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/14 16:22:00 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "struct.h"

int 	ft_execute(t_cmd *cmd, char **envp);
char	*truepath(char *cmd, char **env);
void	free_cmdpath(char **s_path, char **s_cmd);
char	*pathfinder(char **env);
char	*ft_strjoinslash(char const *s1, char const *s2);

//Built-in
int		ft_pwd(void);
int		ft_executebuiltin(t_cmd *cmd, char **env);
int		ft_env(char **env);
int		ft_cd(char **cmd, char **env);
char*	ft_findhome(char **env);

#endif