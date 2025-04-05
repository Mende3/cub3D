#include "../../includes/cub3D.h"

int ft_strcmp (const char *s1,const char *s2)
{
    int i;

    i = 0;
    while ((s1[i] || s2[i]) && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char *ft_strstr(const char *haystack, const char *needle)
{
    if (haystack[0] == '\t' || haystack[0] == 32)
        return NULL;
    while (*haystack)
    {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && (*h == *n))
        {
            h++;
            n++;
        }
        if (*n == '\0')
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}

int extension_checker (const char *arg, const char *ext)
{
    const char *dot;

    dot = ft_strchr (arg, '.');
	if (!dot || dot == arg)
		return (FALSE);
	return (ft_strcmp((char *)(dot + 1), (char *)ext) == 0);
}

int ft_isspace(int c)
{
    return (c == ' '  || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}
