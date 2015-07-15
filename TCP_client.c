#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */

int main(int argc, char **argv)
{
	if(3 != argc)
	{
		printf("Usage: %s <IP> <PORT>\n", argv[0]);
		return -1;
	}

	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sock_fd)
	{
		perror("ssss");
		return -1;
	}

	struct sockaddr_in serveraddr = {0};
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = atoi(argv[2]);
	int len = sizeof(serveraddr);

	if(-1 == connect(sock_fd, (struct sockaddr*)&serveraddr, len))
	{
		perror("connect");
		return -1;
	}

	char buf[100] = {0};
	while(1)
	{
		printf("input: ");fflush(stdout);
		gets(buf);

		write(sock_fd, buf, 100);
		read(sock_fd, buf, 100);
		
		printf("recv : %s\n", buf);
	}
}
