/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:34:30 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/13 16:52:18 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_cpyenv(char **env_cpy, char **envp)
{
	int i;

	i = 0;
	while(envp[i])
	{
		ft_strlcpy(env_cpy[i], envp[i], (ft_strlen(envp[i]) + 1));
		i++;
	}
}

int ft_initstruct(t_info *info, char **envp)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	while (envp[count])
		count++;
	info->cmd_list = NULL;
	info->env = malloc((count + 1) * (sizeof (char*)));
	while (envp[i])
	{
		info->env[i] = malloc((ft_strlen(envp[i]) + 1) * (sizeof(char)));
		i++;
	}
	ft_cpyenv(info->env, envp);
	return (0);
}