#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 100
int load_data(int fd, char (*data)[100])
{
	lseek(fd, 0, SEEK_SET);
	int i = 0;
	for(;i<N; i++)
	{
		if(0 == read(fd, data[i], 100))
			break;
	}
	return i;
}

int main()
{
	char data[N][100] = {0};
	int fd = open("my.db", O_RDWR);
	if(-1 == fd)
	{
		perror("open");
		return -1;
	}

	int n = load_data(fd, data);
	printf("%d data loaded !\n", n);

	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sock_fd)
	{
		perror("ssss");
		return -1;
	}

	struct sockaddr_in myaddr = {0}, clientaddr = {0};
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	myaddr.sin_port = 8888;
	int len = sizeof(myaddr);
	
	if(-1 == bind(sock_fd, (struct sockaddr*)&myaddr, len))
	{
		perror("bind");
		return -1;
	}

	listen(sock_fd, 10);
	int client_fd = accept(sock_fd, (struct sockaddr*)&clientaddr, &len);
	
	printf("incoming IP: %s\n",  inet_ntoa(clientaddr.sin_addr));
	//get "net file" -> client_fd
	
	char buf[200] = {0};
	while(1)
	{
		read(client_fd, buf, 100);
		if(0 == strcmp("time", buf))
		{
			strcpy(buf, "11:30");
		}		
		else
		if(0 == strncmp("select", buf, 6))
		{
			int i = 0;
			for(;i<2;i++)
			{
				if(0 == strcmp(data[i], buf+7))
				{
			
					strcpy(buf, "OK");
					break;
				}
				strcpy(buf, "NO");
			
			}
		}		
		else
		if(0 == strncmp("register", buf, 8))
		{
			lseek(fd, 0, SEEK_END);
			write(fd, buf+9, 100);
			n = load_data(fd, data);
			printf("%d data loaded !\n", n);
			strcpy(buf, "OK");
		}
		else
		{
			strcpy(buf, "cmd err!!!");

		}
		write(client_fd, buf, 100);
	}
}
