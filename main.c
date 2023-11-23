#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h>  
#include <sys/types.h> 
#include <unistd.h>  
#include <signal.h> 
#include <string.h> 



int main(void){ 

	int sockfd = socket(AF_UNIX, SOCK_STREAM, 0); 
	if(sockfd == -1){
		perror("socket");   
		return; 
	}

	struct sockaddr addr = {AF_UNIX, "InofSock"} 
	



}  
