#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(){

	int fd = open("lyy.bmp", O_RDWR);
	//char buf[] = "lizhengxiang";
	int a = 720*960*3/2+(350*3), i;
	
	for( i = 0; i < 80; i++){
		int t = a;
		lseek(fd, a, SEEK_SET);	
		char buf[160] = {0};
		read(fd, buf, 160);
		int h = 0, b = 160;
		int m = 0;
		for(m = 0; m < 80; m++, h++, b--){
			char temp = buf[b]+20+m;
			buf[b] = buf[h]-20-m;
			buf[h] = temp;
		}
		lseek(fd, a, SEEK_SET);
		write(fd, buf, 160);
		a += 720*3;
	}
	close(fd);
	return 0;
}
