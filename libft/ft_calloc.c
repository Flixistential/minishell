/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:47:37 by fboivin           #+#    #+#             */
/*   Updated: 2023/11/23 14:45:47 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftps.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	
	ptr = (char *)malloc(count * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}
