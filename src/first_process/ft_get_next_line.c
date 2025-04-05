#include <stdlib.h>
#include <unistd.h>
#include "../../includes/cub3D.h"

char *get_next_line(int fd)
{
    char c;

    if (fd < 0)
        return NULL;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer)
        return NULL;
    int i = 0;    
    while (read(fd, &c, 1) > 0) 
    {
        if (i >= BUFFER_SIZE - 1)
            break;
        buffer[i++] = c;
        if (c == '\n')
            break;
    }
    if (i == 0)
    {
        free(buffer);
        return NULL;
    }
    buffer[i] = '\0';
    return buffer;
}
