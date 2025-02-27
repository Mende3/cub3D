#include "../../includes/cub3D.h"

char	*ft_strchr(const char *s, int c)
{
	char	find_c;

	if (!s)
		return (NULL);
	find_c = c;
	while (*s != find_c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
