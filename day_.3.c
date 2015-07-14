#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(){

	int fd = open("hello_2.txt", O_RDWR);
	char buf[] = "lizhengxiang";
	int i, j;
	int a = sizeof(buf);
	printf("%d\n", a);
	write(fd, buf, a);
	printf("%s\n", buf);
	
	read(fd, buf, 9);
	printf("%s*******\n\n", buf);
	
	for(i = 0, j = 9; i <= j; i++, j--){
		char temp = buf[i];
		buf[i] = buf[j];
		buf[j] = temp;
		printf("%c\t%c\t", buf[i], buf[j]);
	}
	printf("\n%s\n", buf);
	printf("\n");
	lseek(fd, 0, SEEK_SET);
	write(fd, buf, 9);
	close(fd);
	return 0;
}
