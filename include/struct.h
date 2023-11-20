
#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"
# include <unistd.h>
# include <stdbool.h>

enum e_error_list{
	FAILURE,
	SUCESS,
	MALLOC_FAIL,
	AHJSKDHIA,
	AFSDF = 400,
	ADJASDJK
};

typedef struct s_cmd
{
	char			**cmd;
	char			*token;
	pid_t			pid;
	struct s_cmd	*next;
	bool			built_in;
}			t_cmd;

typedef struct s_info
{
	t_cmd			*cmd_list;
	char			**env;
}			t_info;

int	ft_initstruct(t_info *info, char **envp);

#endif
