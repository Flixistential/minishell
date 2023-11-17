/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:11:24 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/17 15:42:33 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int env_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**unset_var(int unset_index, char **env)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	if (!(new_env = malloc(env_len(env) * sizeof(char *))))
		return (NULL);
	while (env[i])
	{
		if (i == unset_index)
		{
			if ((env[unset_index + 1]))
				i++;
			else
				break;
		}
		new_env[j] = ft_strdup(env[i]);
		i++;
		j++;
	}
	ft_free(env);
	new_env[i] = NULL;
	return (new_env);
}

int	env_finder(char *str, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && (env[i][j] != str[0]))
			j++;
		if (ft_strncmp(env[i], str, (ft_strlen(str))) == 0)
		{
			if(env[i][(ft_strlen(str))] == '=')
				return (i);
		}
		i++;
	}
	return (-1);
}

int ft_unset(char **cmd, char **env)
{
    int i;
    int j;

	/*i = 0;
	while (env[i])
	{
		printf("ENV 1 ======= %s\n", env[i]);
		i++;
	}*/
    i = 1;
    if (!cmd[1] || !env)
        return(SUCESS);
    while(cmd[i])
    {
        j = env_finder(cmd[i], env);
		printf("%d\n", j);
        if (0 <= j)
            env = unset_var(j , env);
        i++;
    }
	i = 0;
	while (env[i])
	{
		printf("ENV 2 ======= %s\n", env[i]);
		i++;
	}
	return (0);
}