/*
** FASTA_TOOLS PROJECT, 2023
** SBML
** File description:
** copy_content_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char *copy_content_file(char *file)
{
    struct stat sb;
    int fd = 0;
    char *buffer = NULL;

    if (stat(file, &sb) == -1)
        return NULL;
    buffer = malloc((sizeof(char)) * (sb.st_size + 1));
    if (buffer == NULL) {
        return NULL;
    }
    fd = open(file, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
    if (read(fd, buffer, sb.st_size) == -1)
        return NULL;
    buffer[sb.st_size] = '\0';
    if (close(fd) == -1)
        return NULL;
    return buffer;
}
