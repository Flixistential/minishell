/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:26:47 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/18 00:02:15 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"
# include <unistd.h>
# include <stdbool.h>

enum error_list{
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
	pid_t 			pid;
	struct s_cmd	*next;
	bool			built_in;
}			t_cmd;

typedef struct s_info
{
	t_cmd			*cmd_list;
	char			**env;
}			t_info;

int ft_initstruct(t_info *info, char **envp);

#endif
