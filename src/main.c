
#include "../include/minishell.h"

void ft_close(t_info *inf)
{
	inf->cmd_list = inf->head;

	while(inf->cmd_list)
	{
		close(inf->cmd_list->fd_in);
		close(inf->cmd_list->fd_out);
		inf->cmd_list = inf->cmd_list->next;
	}
	inf->cmd_list = inf->head;
}

int ft_inputredir(t_cmd **cmd)
{
	int fd[2];

	if(cmd[0]->index == 1)
	{
		//cmd[0]->fd_in = dup(STDIN_FILENO);
		cmd[0]->fd_in = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (cmd[0]->next)
	{
		pipe(fd);
		cmd[0]->fd_out = fd[1];
		cmd[0]->next->fd_in = fd[0];
	}
	return(SUCESS);
}

int	ft_outputredir(t_cmd **cmd)
{
	if(!cmd[0]->next)
	{
		printf("%d\n", cmd[0]->index);
		cmd[0]->fd_out = dup(STDOUT_FILENO);
	}
	return(SUCESS);
}

int index_command(t_info *inf)
{
	t_cmd *temp;

	inf->cmd_count = 0;
	temp = inf->cmd_list;
	if (temp)
		inf->cmd_count++;
	while(temp)
	{
		temp->index = inf->cmd_count;
		inf->cmd_count++;
		temp = temp->next;
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
	ft_inputredir(&temp);
	ft_outputredir(&temp);
	return(0);
}


int ft_pipe(t_cmd *cmd_list)
{
	int fd[2];

	if (!pipe(fd))
		return (FAILURE);
	{
	cmd_list->fd_out = fd[1];
	cmd_list->next->fd_in = fd[0];
	}
	return(SUCESS);
}

void ft_cmdloop(t_info *inf)
{
	index_command(inf);
	while (inf->cmd_list != NULL)
	{
		if (inf->cmd_list)
			ft_redirection(inf);
		inf->cmd_list = inf->cmd_list->next;
	}
	inf->cmd_list = inf->head;
	while (inf->cmd_list != NULL)
	{
		ft_execute(inf);
		inf->cmd_list = inf->cmd_list->next;
	}
}

int ft_temptakecommand(int argc, char **argv, t_info *info)
{
	int	i;

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
	ft_close(&info);
	while (info.cmd_list != NULL)
	{
		waitpid(info.cmd_list->pid, NULL, 0);
		info.cmd_list = info.cmd_list->next;
	}
}
