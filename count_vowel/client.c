#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
	struct sockaddr_in server;
	int sfd,client_sfd;
	char msg[100] ;
	
	int x;
	server.sin_family=AF_INET;
	server.sin_port=2000;
	server.sin_addr.s_addr=INADDR_ANY;
	
	sfd=socket(AF_INET,SOCK_STREAM,0);
	
	client_sfd=connect(sfd,(struct sockaddr*)&server,sizeof(server));
	
	printf("Enter you string : ");
	scanf("%[^\n]%*c",msg);
	//gets(msg);

	send(sfd, msg, strlen(msg), 0);
	
	recv(sfd, &x, sizeof(int), 0);
	printf("Total Vowels : %d\n",x);
	
	close(client_sfd);
		
	return 0;
}