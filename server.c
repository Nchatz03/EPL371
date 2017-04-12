#include "options.h"
#include "lib.h"
#include "components.h"
void reverse(char *);

// void getOption(char * servername,int contentlength,char * connection,char * contenttype,char * requestitem){
//   printf("nikolas\n");

//     FILE * item=NULL;
//     char buff[1000000];
//     char temp;
//     int i=0;
//      item = fopen(requestitem,"r");
//     if(item!=NULL){
//     	printf("HTTP/1.1 200 OK\n");
//     	printf("Server: %s\n",servername);
//     	printf("Content-Length: %d\n",contentlength);
//     	printf("Connection: %s\n",connection);
//     	printf("Content-Type: %s\n",contenttype);
//     	printf("\n");

//     	while( (temp=fgetc(item))!=EOF ){
//             buff[i]=temp;
//             i++;
//     	}
//     	printf("%s\n",buff);
//     	fclose(item);
        
//     }else{
//     	printf("HTTP/1.1 404 Not Found\n" );
//     	printf("Server: %s\n",servername);
//     	printf("Content-Length: 20\n");
//     	printf("Connection: %s\n",connection);
//     	printf("Content-Type: %s\n",contenttype);
//     	printf("\n");
//     	printf("Document not found!\n");
//     }

// }

int getClientOption(char* header, char* result){

if(*header<33){
	*result='\0';
	return 0;
}
else{
char* p=header;
while( *p!=' '){
	if(*p=='\0'){
		return 0;
	}
	*result=*p;
	p++;
	result++;
}

*result='\0';
return 1;
}

}



int getPath(char* header, char* result){
	char temp[40];
  	char * resultcp=result;
  	char* header2=header;
  	if(getClientOption(header2,temp)){
  		
     	while(*header!=' '){
     		header++;
     	}
     	header++;
		if(*header!='/'){
			*result='\0';
			return 0;
		}
     	header++;
     
     	while(*header!=' '){
            if(*header=='\0'){
            	*resultcp='\0';
            	return 0;
            }
     		*result=*header;
     		result++;
     		header++;
     	}
        
     	*result='\0';
     	return 1;   
  	}
  	else{
  		*result='\0';
  		return 0;
  	}
}


int getType(char* header, char* result ){
	char temp[100];
	
if(getPath(header,temp)){
	char *p=temp;
	char *p2=temp;
   while(*p2!='\0'){
   	p2++;
   }
   while(*p2!='.'){
   		if(p2==p){
   			*result='\0';
   			return 0;
   		}
   		p2--;
   }
   
   while(*p2!='\0'){
   	*result=*p2;
   	p2++;
   	result++;
   }
   *result='\0';
   return 1;

}else{
	*result='\0';
	return 0;
}

}


char test[200];

// function prototype for reversing func.
/* Server with Internet stream sockets */
main(int argc, char *argv[]) {
	int port, sock, newsock, serverlen, clientlen;
	char buf[2560];
	struct sockaddr_in server, client;
	struct sockaddr *serverptr, *clientptr;
	struct hostent *rem;
   char path[25];
char filename[25];
char filetype[25];
char clientoption[25];
// char body[1000000];
char* body;
int flag=0;
int size;



	if (argc < 2) { /* Check if server's port number is given */
		printf("Please give the port number \n");
		exit(1);
	}

	/* Create socket */
	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}
	/* Convert port number to integer */
	port = atoi(argv[1]);
	server.sin_family = PF_INET; /* Internet domain */
	server.sin_addr.s_addr = htonl(INADDR_ANY); /* My Internet address */
	server.sin_port = htons(port); /* The given port */
	serverptr = (struct sockaddr *) &server;
	serverlen = sizeof(server);

	/* Bind socket to address */
	if (bind(sock, serverptr, serverlen) < 0) {
		perror("bind");
		exit(1);
	}
	/* Listen for connections */
	if (listen(sock, 5) < 0) {
		/* 5
		 max. requests in queue */
		perror("listen");
		exit(1);
	}
	printf("Listening for connections to port %d\n", port);

	while (1) {
		clientptr = (struct sockaddr *) &client;
		clientlen = sizeof(client);
		/* Accept connection */
		if ((newsock = accept(sock, clientptr, &clientlen)) < 0) {
			perror("accept");
			exit(1);
		}
		/* Using IP address find DNS name (i.e., reverse DNS)*/
		if ((rem = gethostbyaddr((char *) &client.sin_addr.s_addr,
				sizeof(client.sin_addr.s_addr), client.sin_family)) == NULL) {
			herror("gethostbyaddr");

			exit(1);
		}
		printf("Accepted connection from %s\n", rem->h_name);
         // getOption("ael",25,"close",".txt","index.txt");
		/* Create child for serving the client */
		switch (fork()) {
		case -1:
			perror("fork");
			exit(1);
		case 0: /* Child process */
			do {
	
				bzero(buf, sizeof(buf)); /* Initialize buffer */
				if (read(newsock, buf, sizeof(buf)) < 0) { /* Get message */
					perror("read");
					exit(1);
				}


			        for(int j=0;j<sizeof(clientoption);j++){
    	clientoption[j]='\0';
    }
             for(int j=0;j<sizeof(path);j++){
    	path[j]='\0';
    }
             for(int j=0;j<sizeof(filetype);j++){
    	filetype[j]='\0';
    }
     	
			getClientOption(buf, clientoption)	;
			getPath(buf,path);
			// getFileName(buf,filename);
			getType(buf,filetype);
			char  *type;
			defineContentType(filetype,&type);


    
            for(int j=0;j<sizeof(test);j++){
    	test[j]='\0';
    }
     
            flag= defineRequest(test, clientoption,"keep-alive",type,path,&body,&size);

				printf("Read string: %s\n", buf);
				reverse(buf); /* Reverse message */
 

				if (write(newsock, test, sizeof(test)) < 0) {/* Send message */
					perror("write");
					exit(1);
				}
				
                if (flag)

                if (write(newsock, body, size) < 0) { //Send message 
					perror("write");
					exit(1);
				}
				// printf("%s\n","aellllllllllllll" );


			} while (1); /*Finish on "end" message*/
			close(newsock); /* Close socket */
			exit(0);
		} /* end of switch */
	} /* end of while(1) */
} /* end of main() */

/* Function for reversing a string */
void reverse(char *s) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
