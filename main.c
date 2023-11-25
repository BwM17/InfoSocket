#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h>   
#include <sys/un.h>
#include <sys/types.h> 
#include <unistd.h>  
#include <signal.h> 
#include <string.h> 
#include <arpa/inet.h> 

#define BACKLOG 5

int main(void){ 

	int sockfd = socket(AF_UNIX, SOCK_STREAM, 0); 
	if(sockfd == -1){
		perror("socket");    
		exit(-1);
	}

	struct sockaddr_un addr_un = {AF_UNIX, "/tmp/InfoSock"};   
	size_t addr_un_len = sizeof(addr_un);   


	if(bind(sockfd, (struct sockaddr*) &addr_un, addr_un_len) == -1){  
		perror("bind"); 
		exit(-1);
	}

int clientfd; 
while(1){
	if(listen(sockfd, BACKLOG) == -1){
		perror("listen"); 
		exit(-1);
	};   


	clientfd  = accept(sockfd, NULL, NULL);      
	if(clientfd < 0){
		perror("accpet");   
		exit(-1); 
	} 

	char * buffer  = "Hello There\n";    

	while(1){
		if(send(clientfd, buffer, strlen(buffer), 0) == -1){ 
			perror("send");
			exit(-1); 
		}   
		printf("msg Send"); 
		sleep(5); 
	} 

}
	close(sockfd); 
	close(clientfd); 

	unlink("/tmp/InfoSock"); 
	
	return 0;
}  
