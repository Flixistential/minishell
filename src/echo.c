#include "../include/minishell.h"

//demander au parsing

int ft_echo(char **cmd)
{
	if (!cmd[1])
		printf("\n");
	if (ft_strncmp(cmd[1], "-n", 2))
}