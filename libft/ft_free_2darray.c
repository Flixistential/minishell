/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2darray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:59:11 by oldrolet          #+#    #+#             */
/*   Updated: 2023/11/20 15:59:31 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftps.h"

void	*ft_free_2darray(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
