/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefranci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:32:00 by mefranci          #+#    #+#             */
/*   Updated: 2024/05/23 15:34:32 by mefranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_c(int c)
{
	return (c + '0');
}

static int	count_elements(int n)
{
	int	counter;

	counter = 1;
	while (n / 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static int	check_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*final_string;
	int		counter;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negative = check_negative(n);
	if (is_negative)
		n = -n;
	counter = count_elements(n) + is_negative;
	final_string = (char *) malloc(sizeof(char) * (counter + 1));
	if (!final_string)
		return (NULL);
	final_string[counter] = '\0';
	if (is_negative)
		final_string[0] = '-';
	while (counter-- > is_negative)
	{
		final_string[counter] = to_c(n % 10);
		n = n / 10;
	}
	return (final_string);
}
