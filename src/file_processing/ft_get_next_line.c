#include <stdlib.h>
#include <unistd.h>
#include "../../includes/cub3D.h"

char *get_next_line(int fd)
{
    if (fd < 0)
        return NULL;

    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer)
        return NULL;  // Falha ao alocar memória

    int i = 0;
    char c;
    
    while (read(fd, &c, 1) > 0)  // Lê um caractere por vez
    {
        if (i >= BUFFER_SIZE - 1) // Evita estouro de buffer
            break;

        buffer[i++] = c;

        if (c == '\n')  // Para a leitura ao encontrar um '\n'
            break;
    }
    
    if (i == 0)  // Se não leu nada, libera a memória e retorna NULL
    {
        free(buffer);
        return NULL;
    }

    buffer[i] = '\0';  // Finaliza a string
    return buffer;
}
