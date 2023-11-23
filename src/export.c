
#include "../include/minishell.h"
#include "../libft/libftps.h"

char **ft_exportvar(t_info *inf)
{
	int		i;
	int 	j;
	char	**new_env;
	
	j = 1;
	i = 0;
	if (!(new_env = malloc((env_len(inf->env) + env_len(inf->cmd_list->cmd)) * sizeof(char *))))
		return (NULL);
	while (inf->env[i])	
	{
		new_env[i] = ft_strdup(inf->env[i]);
		i++;
	}
	while(inf->cmd_list->cmd[j])
	{
		new_env[i] = strdup(inf->cmd_list->cmd[j]);
		i++;
		j++;
	}
	new_env[i] = NULL;
	ft_free_2darray(inf->env);
	return (new_env);
}

int print_exp(char **alp_env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (alp_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		while (alp_env[i][j] && alp_env[i][j - 1] != '=')
		{
			ft_putchar_fd(alp_env[i][j], 1);
			j++;
		}
		if (alp_env[i][j - 1] == '=')
		{
			ft_putchar_fd('"', 1);
			while (alp_env[i][j])
			{
				ft_putchar_fd(alp_env[i][j], 1);
				j++;
			}
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
		j = 0;
		i++;
	}
	return (SUCESS);
}

int is_sorted_alpha(char **alp_env)
{
	int i;

	i = 0;
	while(alp_env[i] && alp_env[i + 1])
	{
		if (alp_env[i][0] > alp_env[i + 1][0])
			return (FAILURE);
		i++;
	}
	return (SUCESS);
}

int bbl_srt_alp(char **alp_env)
{
	int		i;
	char	*temp;

	while (!is_sorted_alpha(alp_env))
	{
		i = 0;
		while (alp_env[i] && alp_env[i + 1])
		{
			if (alp_env[i][0] > alp_env[i + 1][0])
			{
				temp = alp_env[i + 1];
				alp_env[i + 1] = alp_env[i];
				alp_env[i] = temp;
			}
			i++;
		}
	}
	return (SUCESS);
}

int ft_dupenv(char **dup_env, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		dup_env[i] = ft_strdup(env[i]);
		i++;
	}
	dup_env[i] = NULL;
	return (0);
}

int export(t_info *inf)
{
    char **alp_env;

    if (!inf->cmd_list->cmd[1])
    {
        alp_env = malloc((ft_x2strlen(inf->env) + 1) * (sizeof(char *)));
        ft_dupenv(alp_env, inf->env);
        bbl_srt_alp(alp_env);
        print_exp(alp_env);
		ft_free_2darray(alp_env);
    }
	else
		inf->env = ft_exportvar(inf);
	return (SUCESS);
}
