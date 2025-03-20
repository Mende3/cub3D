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

void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s", map[i]);
        i++;
    }
    printf("\n");
}

int	colmn_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	lines_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}