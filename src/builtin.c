/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:54:05 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/20 16:03:32 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_findhome(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != 'H')
			j++;
		if (ft_strncmp(env[i], "HOME", 4) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

//check for unset HOME after unset is done

int	ft_cd(char **cmd, char **env)
{
	char	*home;

	if (!cmd[1])
	{
		home = ft_findhome(env);
		chdir(home);
		return (SUCESS);
	}
	if (chdir(cmd[1]) != 0)
	{
		perror("Minishell: cd");
		return (FAILURE);
	}
	return (SUCESS);
}

void	ft_builtincheck(t_cmd *cmd)
{
	if ((!ft_strncmp(cmd->cmd[0], "echo", 5)) || \
	(!ft_strncmp(cmd->cmd[0], "cd", 3)) || \
	(!ft_strncmp(cmd->cmd[0], "pwd", 3)) || \
	(!ft_strncmp(cmd->cmd[0], "export", 7)) || \
	(!ft_strncmp(cmd->cmd[0], "unset", 6)) || \
	(!ft_strncmp(cmd->cmd[0], "env", 4)) || \
	(!ft_strncmp(cmd->cmd[0], "exit", 5)))
		cmd->built_in = true;
	else
		cmd->built_in = false;
}

int	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (SUCESS);
}

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	printf("%s\n", pwd);
	return (SUCESS);
}

int	ft_executebuiltin(t_info *inf)
{
	if (!ft_strncmp(inf->cmd_list->cmd[0], "echo", 5))
		return (0);
	if (!ft_strncmp(inf->cmd_list->cmd[0], "cd", 3)) 
		return (ft_cd(inf->cmd_list->cmd, inf->env));
	if (!ft_strncmp(inf->cmd_list->cmd[0], "pwd", 4))
		return (ft_pwd()); 
	if (!ft_strncmp(inf->cmd_list->cmd[0], "export", 7))
		return (0); 
	if (!ft_strncmp(inf->cmd_list->cmd[0], "unset", 6))
		return (ft_unset(inf));
	if (!ft_strncmp(inf->cmd_list->cmd[0], "env", 4))
		return (ft_env(inf->env));
	if (!ft_strncmp(inf->cmd_list->cmd[0], "exit", 5))
		exit(0);
	return (0);
	if (!inf->env)
		return (FAILURE);
}
