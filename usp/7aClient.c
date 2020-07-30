#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h> 
#define SERV_TCP_ADDR "127.0.0.1"
#define SERV_TCP_PORT 8000
#define MAX 1000
int main()
{
	int sockfd,bytes,clilen,n,fp;
	struct sockaddr_in address,cli_addr,serv_addr;
	char buffer[MAX];

	printf("Enter the filename\n");
	scanf("%s",buffer);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(SERV_TCP_ADDR);
	serv_addr.sin_port=SERV_TCP_PORT;

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	printf("\nSocket Error");

	//printf("%s\n",buffer);
	if((connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))<0)
		printf("Connect Error\n");
	bytes=send(sockfd,buffer,sizeof(buffer),0);
	while((bytes=recv(sockfd,buffer,sizeof(buffer),0))>0)
	{
		 printf("%s",buffer);
	}
	close(sockfd);
	//exit(0);
}
