#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fdi = open("foo.txt", O_RDONLY);
    int fdo = open("bar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char *c = (char *) calloc(100, sizeof(char));

    while(read(fdi, c, 100)){
	    strcat(c, "\0");
	    write(fdo, c, strlen(c));
    }

    close(fdi);
    close(fdo);
}
