
#include "../include/minishell.h"

int index_command(t_info *inf)
{
	t_cmd *temp;

	inf->cmd_count = 0;
	temp = inf->cmd_list;
	while(temp)
	{
		temp = temp->next;
		inf->cmd_count++;
		temp->index = inf->cmd_count;
	}
	if(inf->cmd_count >= 1)
		return (SUCESS);
	else
		return (FAILURE);
}

int ft_redirection(t_info *inf)
{
	t_cmd 	*temp;

	temp = inf->cmd_list;
	while(temp->next != NULL)
	{
		ft_inputredir();
		ft_outputredir();
	}
}


ft_pipe(t_cmd *cmd_list)
{
	int fd[2];

	if (!pipe(fd))
		return (FAILURE);
	{
	cmd_list->fd_out = fd[1];
	cmd_list->next->fd_in = fd[0];
	}

}

void ft_cmdloop(t_info *inf)
{
	index_command(inf);
	while (inf->cmd_list != NULL)
	{
		if (inf->cmd_list->next)
			ft_redirection(inf->cmd_list);
		ft_execute(inf);
		inf->cmd_list = inf->cmd_list->next;
	}

}

int ft_temptakecommand(int argc, char **argv, t_info *info)
{
	int 	i;

	i = 1;
	while (i < argc)
	{
		ft_cmdadd_back(&info->cmd_list ,ft_lstnewcmd(argv[i]));
		i++;
	}
	info->head = info->cmd_list;
	if (info->head != NULL)
		return (SUCESS);
	else
		return (FAILURE);
}

/*int	main(int argc, char **argv, char **envp)
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
}*/

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		i;

	i = argc;
	if (argv)
		i++;
	ft_initstruct(&info, envp);
	ft_temptakecommand(argc, argv, &info);
	ft_cmdloop(&info);
	info.cmd_list = info.head;
	while (info.cmd_list != NULL)
	{
		waitpid(info.cmd_list->pid, NULL, 0);
		info.cmd_list = info.cmd_list->next;
	}
}