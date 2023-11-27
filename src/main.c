
#include "../include/minishell.h"

t_cmd	*ft_cmdlast(t_cmd *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}


void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		temp = ft_cmdlast (*lst);
		temp->next = new;
		return ;
	}
	*lst = new;
}


void ft_cmdloop(t_info *inf)
{
	while (inf->cmd_list != NULL)
	{
		ft_execute(inf);
		inf->cmd_list = inf->cmd_list->next;
	}

}

t_cmd	*ft_lstnewcmd(char *cmd)
{
	t_cmd	*elm;

	elm = malloc(sizeof(t_cmd));
	if (!elm)
		return (NULL);
	elm->cmd = ft_split(cmd, ' ');
	elm->token = NULL;
	ft_builtincheck(elm);
	elm->next = NULL;
	return (elm);
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