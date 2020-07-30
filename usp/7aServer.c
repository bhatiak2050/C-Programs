#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<stdlib.h>
#define SERV_TCP_PORT 8000
#define MAX 1000
int main()
{
	int pid,sockfd,bytes,newsockfd,n,fp;
	unsigned int clilen;
	struct sockaddr_in cli_addr,serv_addr;
	char buffer[MAX],errormsg[]="FileOpenError";
	
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
		printf("\nSocket Error\n");

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=(INADDR_ANY);
	serv_addr.sin_port=(SERV_TCP_PORT);
	if((bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))<0)
		printf("Bind Error");

	listen(sockfd,5);
	
	for(;;)
	{
		clilen=sizeof(cli_addr);
		newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
		if(newsockfd<0)
			printf("Server Accept Error");
		if((pid=fork())<0)
			printf("Fork Error");
		else
		if(pid==0)
		{
			close(sockfd);
			bytes=recv(newsockfd,&buffer,MAX,0);
			printf("%s\n",buffer);
			fp=open(buffer,O_RDONLY);
			if(fp<0)
			{
				send(newsockfd,errormsg,sizeof(errormsg),0);
				printf("open error\n");
				exit(0);
			}
			//printf("%s",buffer);
			while((n=read(fp,buffer,MAX))>0)
			{
				bytes=send(newsockfd,buffer,n,0);
			}
				close(newsockfd);
			exit(0);
		}
	}
}
