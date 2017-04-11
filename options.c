#include "options.h"
#include "lib.h"

void getOption(char * stream,char * connection,char * contenttype,char * requestitem){

	#ifndef DEBUG
    FILE * item=NULL;
    char buff[1000000];
    char temp;
    int i=0;
    int size=0;
     item = fopen(requestitem,"r");
    if(item!=NULL){
    	while( (temp=fgetc(item))!=EOF ){
            buff[i]=temp;
            i++;
            size++;
    	}
    	buff[i]='\0';
    	sprintf(stream, "HTTP/1.0 200 OK\r\n");
    	sprintf(stream, "%sServer: My_server\r\n", stream);
    	sprintf(stream, "%sContent-Length: %d\n\r",stream,size);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n",stream,contenttype);
    	sprintf(stream,"%s%s\n\r",stream,buff);
    	fclose(item);
        
    }else{

    	sprintf(stream,"HTTP/1.1 404 Not Found\n\r" );
    	sprintf(stream,"%sServer: My_server\n\r",stream);
    	sprintf(stream,"%sContent-Length: 20\n\r",stream);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	sprintf(stream,"%sDocument not found!\n\r",stream);
    }
    #endif

    #ifdef DEBUG

    FILE * item=NULL;
    char buff[1000000];
    char temp;
    int i=0;
    int size=0;
     item = fopen(requestitem,"r");
    if(item!=NULL){
    	while( (temp=fgetc(item))!=EOF ){
            buff[i]=temp;
            i++;
            size++;
    	}
    	buff[i]='\0';
    	printf("HTTP/1.0 200 OK\r\n");
    	printf("Server: My_server\r\n");
    	printf("Content-Length: %d\n\r",size);
    	printf("Connection: %s\n\r",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("%s\n\r",buff);
    	fclose(item);
        
    }else{

    	printf("HTTP/1.1 404 Not Found\n\r" );
    	printf("Server: My_server\n\r");
    	printf("Content-Length: 20\n\r");
    	printf("Connection: %s\n\r",connection);
    	printf("Content-Type: %s\n\r",contenttype);
    	printf("Document not found!\n\r");
    }

    #endif


}

void headOption(char * stream,char * connection,char * contenttype,char * requestitem){
    
    #ifndef DEBUG

    FILE * item;
    	
    item = fopen(requestitem,"r");

	if(item!=NULL){
		fclose(item);
    	sprintf(stream,"HTTP/1.1 200 OK\n\r");
    	sprintf(stream,"%sServer: My_server \n\r",stream);
    	sprintf(stream,"%sContent-Length: %d\n",stream,30);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);       
    }else{
    	sprintf(stream,"HTTP/1.1 404 Not Found\n\r");
    	sprintf(stream,"%sServer: My_server\n\r",stream);
    	sprintf(stream,"%sContent-Length: 20\n\r",stream);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	sprintf(stream,"%s\n\r",stream);
    	sprintf(stream,"%sDocument not found!\n\r",stream);
    }


    #endif

    #ifdef DEBUG

    FILE * item;
    	
    item = fopen(requestitem,"r");

    if(item!=NULL){
		fclose(item);
    	printf("HTTP/1.1 200 OK\n\r");
    	printf("Server: My_server \n\r");
    	printf("Content-Length: %d\n",30);
    	printf("Connection: %s\n\r",connection);
    	printf("Content-Type: %s\n\r",contenttype);       
    }else{
    	printf("HTTP/1.1 404 Not Found\n\r");
    	printf("Server: My_server\n\r");
    	printf("Content-Length: 20\n\r");
    	printf("Connection: %s\n\r",connection);
    	printf("Content-Type: %s\n\r",contenttype);
    	printf("\n\r");
    	printf("Document not found!\n\r");
    }

    #endif

}

void deleteOption(char * stream, char * connection,char * contenttype,char * requestitem){

    #ifndef DEBUG

	int errorflag;

	errorflag = remove(requestitem);

    if(errorflag == 0){
        sprintf(stream,"HTTP/1.1 204 No Content\n\r");
    	sprintf(stream,"%sServer: My_server\n\r",stream);
    	sprintf(stream,"%sContent-Length: 16\n\r",stream);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	sprintf(stream,"%s\n\r",stream);
    	sprintf(stream,"%sDocument deleted\n\r",stream);
    }else{
    	sprintf(stream,"%sHTTP/1.1 404 Not Found\n\r" );
    	sprintf(stream,"%sServer: My_server\n\r",stream);
    	sprintf(stream,"%sContent-Length: 20\n\r",stream);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	sprintf(stream,"%s\n\r",stream);
    	sprintf(stream,"%sDocument not found!\n\r",stream);

    }

    #endif

    #ifdef DEBUG

    int errorflag;

	errorflag = remove(requestitem);

    if(errorflag == 0){
        printf("HTTP/1.1 204 No Content\n\r");
    	printf("Server: My_server\n\r");
    	printf("Content-Length: 16\n\r");
    	printf("Connection: %s\n\r",connection);
    	printf("Content-Type: %s\n\r",contenttype);
    	printf("\n\r");
    	printf("Document deleted\n\r");
    }else{
    	printf("HTTP/1.1 404 Not Found\n\r" );
    	printf("Server: My_server\n\r");
    	printf("Content-Length: 20\n\r");
    	printf("Connection: %s\n\r",connection);
    	printf("Content-Type: %s\n\r",contenttype);
    	printf("\n\r");
    	printf("Document not found!\n\r");

    }

    #endif
}

void notImplementedOption(char *stream ,char * connection,char * contenttype){
    
        sprintf(stream,"HTTP/1.1 501 No Implemented\n\r");
    	sprintf(stream,"%sServer: My_server\n\r",stream);
    	sprintf(stream,"%sContent-Length: 24\n\r",stream);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	sprintf(stream,"%s\n\r",stream);
    	sprintf(stream,"%sMethod not implemented\n\r",stream);
}

void notAnOption(char* stream){

    sprintf(stream,"HTTP/1.1 406 Not Acceptable\n\r");

}


#ifdef DEBUG

/* Declaring Object Unit tests */
int main(){
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                           THIS IS A DEBUGGING CALL FOR OPTION.c                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|   void getOption(char * stream,char * connection,char * contenttype,char * requestitem)   |\n");
printf("|                                  TESTING FOR EXCEPTIONS                                   |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|TESTING CHAR* REQUESTITEM                                                                  |\n");
printf("|                                                                                           |\n");
printf("|1st try: existing file (debug.txt)                                                         |\n");
printf("|2nd try: NOT existing file (debug.ttxt)                                                    |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                                         1ST TRY                                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* stream = NULL \n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
/* Declaring Object Unit tests */
char* stream = NULL;
char* connection = "TEST MODE";
char* contenttype = "TEST MODE";
char* requestitem = "debug.txt";
getOption(stream,connection,contenttype,requestitem);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                                         2ND TRY                                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* stream = NULL \n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.ttxt}\n");
/* Declaring Object Unit tests */
stream = NULL;
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.ttxt";
getOption(stream,connection,contenttype,requestitem);
printf("\n");
printf("\n");







printf("*********************************************************************************************\n");
printf("*********************************************************************************************\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|   void headOption(char * stream,char * connection,char * contenttype,char * requestitem)  |\n");
printf("|                                  TESTING FOR EXCEPTIONS                                   |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|TESTING CHAR* REQUESTITEM                                                                  |\n");
printf("|                                                                                           |\n");
printf("|1st try: existing file (debug.txt)                                                         |\n");
printf("|2nd try: NOT existing file (debug.ttxt)                                                    |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                                         1ST TRY                                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* stream = NULL \n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
/* Declaring Object Unit tests */
stream = NULL;
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
headOption(stream,connection,contenttype,requestitem);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                                         2ND TRY                                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* stream = NULL \n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.ttxt}\n");
/* Declaring Object Unit tests */
stream = NULL;
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.ttxt";
headOption(stream,connection,contenttype,requestitem);
printf("\n");
printf("\n");











printf("*********************************************************************************************\n");
printf("*********************************************************************************************\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("| void deleteOption(char * stream,char * connection,char * contenttype,char * requestitem)  |\n");
printf("|                                  TESTING FOR EXCEPTIONS                                   |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|TESTING CHAR* REQUESTITEM                                                                  |\n");
printf("|                                                                                           |\n");
printf("|1st try: existing file (debug.txt)                                                         |\n");
printf("|2nd try: NOT existing file (debug.ttxt)                                                    |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                                         1ST TRY                                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* stream = NULL \n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
/* Declaring Object Unit tests */
stream = NULL;
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
deleteOption(stream,connection,contenttype,requestitem);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------|\n");
printf("|                                         2ND TRY                                           |\n");
printf("|-------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* stream = NULL \n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.ttxt}\n");
/* Declaring Object Unit tests */
stream = NULL;
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.ttxt";
deleteOption(stream,connection,contenttype,requestitem);
printf("\n");
printf("\n");
printf("\n");









}
#endif

