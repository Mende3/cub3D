/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefranci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:32:00 by mefranci          #+#    #+#             */
/*   Updated: 2024/05/23 15:35:35 by mefranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*memory_src;
	unsigned char	*memory_dst;
	size_t			counter;

	memory_src = (unsigned char *)src;
	memory_dst = (unsigned char *)dst;
	counter = len;
	if (memory_src < memory_dst)
	{
		while (counter)
		{
			counter--;
			memory_dst[counter] = memory_src[counter];
		}
		return (dst);
	}
	ft_memcpy(memory_dst, memory_src, len);
	return (dst);
}
