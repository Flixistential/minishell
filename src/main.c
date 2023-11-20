/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:30:13 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/20 16:17:29 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	t_cmd	cmd;
	int		i;
	char	*str;

	i = argc;
	if (argv)
		i++;
	ft_initstruct(&info, envp);
 	while (true)
 	{
    	str = readline("Minishell :");
		info.cmd_list = &cmd;
		info.cmd_list->cmd = ft_split(str, ' ');
		//printf("%s\n", info.cmd_list->command);
		ft_builtincheck(&cmd);
    	ft_execute(&info);
		waitpid(info.cmd_list->pid, NULL, 0);
    	free(str);
	}
}
