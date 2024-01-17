#include "../include/minishell.h"

int ft_heredoc(t_cmd *cmd)
{
	int fd;

	fd = ft_makedoc(cmd);
	ft_editdoc(fd ,cmd);
	return(0);
}

int ft_editdoc(int fd, t_cmd *cmd)
{
	char *tmp;
	
	tmp = NULL;
	while(ft_strncmp("stop", tmp, 4) != 0)
	{
		tmp = readline("heredoc >");
			if (cmd)
		ft_putendl_fd(tmp, fd);
	}
	return (SUCESS);
}

int ft_makedoc(t_cmd *cmd)
{
	int fd;
	static int i;

	if(cmd)
		i = 1;
	fd = open("heredoc", O_CREAT | O_TRUNC | O_RDWR, 0644);
	return(fd);
}