#include "cub3d.h"

int main(int argc, char const *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char *line = (char*)malloc(sizeof(char));
	while(get_next_line(fd, &line) > 0)
		printf("%s\n", line);
    return 0;
}
