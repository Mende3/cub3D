#include "../../includes/cub3D.h"

int ft_strcmp (const char *s1,const char *s2)
{
    int i;

    i = 0;
    while ((s1[i] || s2[i]) && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int extension_checker (const char *arg, const char *ext)
{
    const char *dot;

    dot = ft_strchr (arg, '.');
	if (!dot || dot == arg)
		return (FALSE);
	return (ft_strcmp((char *)(dot + 1), (char *)ext) == 0);
}