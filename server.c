/* File: server.c */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>






/*
/*
/*
/*
/*
For
For
For
For
For
sockets */
//sockets */
//Internet sockets */
//gethostbyaddr() */
//I/O */
//void reverse(char *); // function prototype for reversing func.
/* Server with Internet stream sockets */
main(int argc, char *argv[]) {

 char http_not_found[] = "HTTP/1.0 404 Not Found\n";
 char http_ok[] = "HTTP/1.0 200 OK\n";


int port, sock, newsock, serverlen, clientlen; char buf[256];
struct sockaddr_in server, client;
struct sockaddr *serverptr, *clientptr;
struct hostent *rem;
if (argc < 2) { /* Check if server's port number is given */
printf("Please give the port number\n");

}



/* Create socket */
if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
perror("socket"); exit(1); }
/* Convert port number to integer */
port = atoi(argv[1]);
server.sin_family = PF_INET; /* Internet domain */
server.sin_addr.s_addr = htonl(INADDR_ANY); /* My Internet address */
server.sin_port = htons(port); /* The given port */
serverptr = (struct sockaddr *) &server;
serverlen = sizeof (server);
/* Bind socket to address */
if (bind(sock, serverptr, serverlen) < 0) {
perror("bind"); exit(1); }
/* Listen for connections */
if (listen(sock, 5) < 0) {
/* 5 max. requests in queue */
perror("listen"); exit(1); }
printf("Listening for connections to port %d\n", port);



while(1) {
clientptr = (struct sockaddr *) &client;
clientlen = sizeof(client);
/* Accept connection */
if ((newsock = accept(sock, clientptr, &clientlen)) < 0) {
perror("accept");
exit(1);
}
/* Using IP address find DNS name (i.e., reverse DNS)*/
if ((rem = gethostbyaddr((char *) &client.sin_addr.s_addr,
sizeof (client.sin_addr.s_addr), client.sin_family)) == NULL) {
herror("gethostbyaddr"); // herror(): Similar to perror but uses the h_errno
//variable (set by name resolution functions to return error values).
exit(1);
}
printf("Accepted connection from %s\n", rem -> h_name);






/* Create child for serving the client */
switch (fork()) {
case -1:

perror("fork"); exit(1);

case 0: /* Child process */
do {
bzero(buf, sizeof(buf)); /* Initialize buffer */
if (read(newsock, buf, sizeof(buf)) < 0) { /* Get message */
perror("read"); exit(1);
}
// if (strcmp(buf,"get")==0){
// 	printf("bye bye\n");
// 	// exit(-1);
// }

printf("Read string: %s\n", buf);
reverse(buf); /* Reverse message */
if (write(newsock, buf, sizeof(buf)) < 0){/* Send message */
perror("write"); exit(1);
}
} while (strcmp(buf, "dne") != 0); /*Finish on "end" message*/
close(newsock); /* Close socket */
exit(0);
} /* end of switch */
} /* end of while(1) */
} /* end of main() */




/* Function for reversing a string */
void reverse(char *s)
{
int c, i, j;
for (i = 0, j = strlen(s) - 1 ; i < j ; i++, j--) {
c = s[i];
s[i] = s[j];
s[j] = c;
}
}