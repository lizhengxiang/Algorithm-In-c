#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
int main(){

	int fd = open("hello.txt", O_RDWR);
	int buf[30];
	int i;
	for(i = 0; i < 30; i++)
		buf[i] = i;
	write(fd, *buf, 9);
	//printf("%s\n", buf);
	close(fd);
	return 0;
}
