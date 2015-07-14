#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
int main(){

	int fd = open("hello.txt", O_RDWR);
	char buf[10] = {0};
	read(fd, buf, 9);
	printf("%s\n", buf);
	close(fd);
	return 0;
}
