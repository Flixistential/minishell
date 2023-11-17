/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:36:00 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/17 15:43:05 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_pwd(void);
int		ft_executebuiltin(t_cmd *cmd, char **env);
int		ft_env(char **env);
int		ft_cd(char **cmd, char **env);
char*	ft_findhome(char **env);
int 	ft_unset(char **cmd, char **env);
int		env_finder(char *str, char **env);
int 	env_len(char **env);

#endif