/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:19 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/17 23:42:53 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "execution.h"
# include "struct.h"
# include "../libft/libftps.h"
# include "builtin.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/file.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include "readline/history.h"
# include "readline/readline.h"

void	ft_builtincheck(t_cmd *cmd);
void	ft_cpyenv(char **env_cpy, char **envp);

/*malloc list : info.env
				readline prompt
*/

#endif