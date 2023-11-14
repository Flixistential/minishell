/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:48:14 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/14 17:08:47 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include  "../include/execution.h"

char	*ft_strjoinslash(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (ptr == 0)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '/';
	i++;
	while (s2[j])
	{
		ptr[i + j] = s2 [j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*pathfinder(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != 'P')
			j++;
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}


void	free_cmdpath(char **s_path, char **s_cmd)
{
	ft_free(s_cmd);
	ft_free(s_path);
}

char	*truepath(char *cmd, char **env)
{
	int		i;
	char	**s_path;
	char	**s_cmd;
	char	*path;

	i = -1;
	s_path = ft_split(pathfinder(env), ':');
	s_cmd = ft_split(cmd, ' ');
	if (access(s_cmd[0], F_OK | X_OK) == 0)
	{
		ft_free(s_path);
		return (s_cmd[0]);
	}
	while (s_path[++i])
	{
		path = ft_strjoinslash(s_path[i], s_cmd[0]);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_cmdpath(s_path, s_cmd);
			return (path);
		}
		free(path);
	}
	free_cmdpath(s_path, s_cmd);
	return (NULL);
}

int	ft_execute(t_cmd *cmd, char **env)
{
	char	*path;
	
	if (cmd->built_in == true)
	{	
		ft_executebuiltin(cmd, env);
		return (SUCESS);
	}
	path = truepath(cmd->command[0], env);
	if (!path)
	{
		ft_putstr_fd("Command not found :", 2);
		ft_putendl_fd(cmd->command[0], 2);
		ft_free(cmd->command);
		return(FAILURE);
	}
	cmd->pid = fork();
	if (cmd->pid == 0)
		execve(path, cmd->command, env);
	return (SUCESS);
}