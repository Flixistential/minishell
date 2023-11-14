/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:54:05 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/13 16:42:03 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_builtinchec(t_cmd *cmd)
{
	if ((!ft_strncmp(cmd->command, "echo", 5)) || \
	(!ft_strncmp(cmd->command, "cd", 3)) || \
	(!ft_strncmp(cmd->command, "pwd", 3)) || \
	(!ft_strncmp(cmd->command, "export", 7)) || \
	(!ft_strncmp(cmd->command, "unset", 6)) || \
	(!ft_strncmp(cmd->command, "env", 4)) || \
	(!ft_strncmp(cmd->command, "exit", 5)))
		cmd->built_in = true;
	else
		cmd->built_in = false;
}

int	ft_env(char **env)
{
	int i;
	
	i = 0;
	while(env[i])
	printf("%s\n", env[0]);
		i++;
	return (0);
}

int		ft_pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	printf("%s\n", pwd);
	return (0);
}

int	ft_executebuiltin(t_cmd *cmd, char **env)
{
	if (!ft_strncmp(cmd->command, "echo", 5))
		return (0);
	if (!ft_strncmp(cmd->command, "cd", 3)) 
		return (0);
	if (!ft_strncmp(cmd->command, "pwd", 3))
		return (ft_pwd()); 
	if (!ft_strncmp(cmd->command, "export", 7))
		return (0); 
	if (!ft_strncmp(cmd->command, "unset", 6))
		return (0);
	if (!ft_strncmp(cmd->command, "env", 4))
		return (ft_env(env));
	if (!ft_strncmp(cmd->command, "exit", 5))
		return (0);
	return (0);
	if (env)
		return (0);
}