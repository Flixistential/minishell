/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:49:05 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/17 15:43:31 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "struct.h"

int 	ft_execute(t_cmd *cmd, char **envp);
char	*truepath(char *cmd, char **env);
void	free_cmdpath(char **s_path, char **s_cmd);
char	*pathfinder(char **env);
char	*ft_strjoinslash(char const *s1, char const *s2);

#endif