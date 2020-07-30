#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd;
	char*myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);
	char arr1[80], arr2[80];

	while(1) {
		fd = open(myfifo, O_WRONLY);
		fgets(arr2, 80, stdin);
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		fd = open(myfifo, O_RDONLY);
		read(fd, arr1, sizeof(arr1));
		printf("user2: %s", arr1);
		close(fd);
	}
}