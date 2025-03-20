/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefranci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:32:00 by mefranci          #+#    #+#             */
/*   Updated: 2024/05/23 15:36:55 by mefranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*str_cpy;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	counter = 0;
	s_len = ft_strlen(s) + 1;
	str_cpy = (char *) malloc(sizeof(char) * s_len);
	if (!str_cpy)
		return (NULL);
	while (s[counter])
	{
		str_cpy[counter] = f(counter, s[counter]);
		counter++;
	}
	str_cpy[counter] = '\0';
	return (str_cpy);
}
