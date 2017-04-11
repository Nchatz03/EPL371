/* File: 
 server.c
 */
#include <sys/types.h> 
/* For sockets */
#include <sys/socket.h> 
/* For sockets */
#include <netinet/in.h> 
/* For Internet sockets */
#include <netdb.h> 
/* For gethostbyaddr() */
#include <stdio.h> 
/* For I/O */
#include <stdlib.h>
#include <string.h>
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

void getPath(char* header, char* result){
   char* p=header;
   char* p1=result;
   while(*p!='/'){
   	p++;
   }
   char*pp =p+1;
   while(*p!=' '){
   	p++;
   }
   char* ppp=p;
   
   
   while(pp!=ppp){
   	*result=*pp;
   	result++;
   	pp++;
   }
   *result='\0';
}

void getFileName(char* header, char* result){
  char* p=header;
   char* p1=result;
   while(*p!='.'){
   	p++;
   }
   while(*p!='/'){
   	p--;
   }
   p++;
   while(*p!=' ')
{
	*p1=*p;
	p1++;
	p++;
}
*p1='\0';
}



void getFileTYpe(char* header, char* result){
 char temp[20];
 getFileName(header,temp);
 char* p=temp;
 while(*p!='.'){
 	p++;
 } 
 // printf("%s",p);
   while(*p!='\0'){
   	*result=*p;
   	result++;
   	p++;
   }
   *result='\0';

}


void getClientOption(char * header, char * result)
{

char* p=header;
while(*p!=' '){
	*result=*p;
	result++;
	p++;
}
*result='\0';

}


char test[100000];

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
// char sendd[10000];

	// sprintf(test, "HTTP/1.0 200 OK\r\n");    //line:netp:servestatic:beginserve
 //   	sprintf(test, "%sServer: Sysstatd Web Server\r\n", test);
 //   	sprintf(test, "%sContent-length: 211\r\n", test);
	// sprintf(test, "%sConnection: keep-alive\r\n", test);
	// sprintf(test, "%sContent-type: text/html\r\n\r\n", test);
	// sprintf(test, "%s<html><head><title>It worked!!!</title></head><body><h1>Yes, It worked!!!</h1>Click at the image to see a sample text!<br><a href=“sample.txt”><img src=“sample.gif”></a></body></html>",test);



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
			getClientOption(buf, clientoption)	;
			getPath(buf,path);
			getFileName(buf,filename);
			getFileTYpe(buf,filetype);
			char  *type;
			defineContentType(filetype,&type);

             defineRequest(test, clientoption,"closed",type,path);

			// printf("sellara\n");

			///////////////////////////////////////////////////////
            // getOption(test,"close",type,path);
            ////////////////////////////////////////////////////////


            /////////////////////////////////////////////////////
            //deleteOption("server",25,"closed",type,path);
            ///////////////////////////////////////////////////////


//headOption("nikolas",25,"close",type,path);

               // printf("aelllllll%d\n",filetype[4] );
				printf("Read string: %s\n", buf);
				reverse(buf); /* Reverse message */


				if (write(newsock, test, sizeof(test)) < 0) {/* Send message */
					perror("write");
					exit(1);
				}

			} while (strcmp(buf, "dne") != 0); /*Finish on "end" message*/
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
