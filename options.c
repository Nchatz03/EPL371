#include "options.h"
#include "lib.h"
#include <sys/stat.h>



void getOption(char * stream,char * connection,char * contenttype,char * requestitem,char ** buff,int* sizee){

    

	#ifndef DEBUG


 
    FILE * item=NULL;
    // char buff[1000000];
    char temp;
    int i=0;
    int size=0;
     item = fopen(requestitem,"rb");
    if(item!=NULL){
   

    	struct stat fstat;
        lstat(requestitem, &fstat);
        size= fstat.st_size;
        *sizee=size;
      
    	fclose(item);
        *buff=malloc(sizeof(char*)*size);
    	item=fopen(requestitem,"rb");
    	fread(*buff, size, 1,item );
    	// buff[i]='\0';
    	sprintf(stream, "HTTP/1.0 200 OK\r\n");
    	sprintf(stream, "%sServer: My_server\r\n", stream);
    	sprintf(stream, "%sContent-Length: %d\r\n",stream,size);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n\r\n",stream,contenttype);

    	fclose(item);
        
    }else{

    	sprintf(stream,"HTTP/1.1 404 Not Found\r\n" );
    	sprintf(stream,"%sServer: My_server\r\n",stream);  	
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n",stream,contenttype);
    	sprintf(stream,"%sContent-Length: 20\r\n\r\n",stream);
    	sprintf(stream,"%sDocument not found!\n",stream);
    	// sprintf(stream,"%s\0",stream);
    }
    #endif

    #ifdef DEBUG

  
    FILE * item=NULL;
    // char buff[1000000];
    char temp;
    int i=0;
    int size=0;
     item = fopen(requestitem,"rb");
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
    	//sprintf(stream,"%s%s\n\r",stream,buff);

    	fclose(item);
        
    }else{

    	sprintf(stream,"HTTP/1.1 404 Not Found\r\n" );
    	sprintf(stream,"%sServer: My_server\r\n",stream);
    	sprintf(stream,"%sContent-Length: 20\r\n",stream);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n\r\n",stream,contenttype);
    	sprintf(stream,"%sDocument not found!\n",stream);
    	sprintf(stream,"%s\0",stream);
    }

    #endif


}

void headOption(char * stream,char * connection,char * contenttype,char * requestitem){
    
    #ifndef DEBUG
    

    
    FILE * item;
    int size=0;	
    char temp;
    item = fopen(requestitem,"r");

// while( (temp=fgetc(item))!=EOF ){
//             size++;
//     	}
	if(item!=NULL){
		struct stat fstat;
        lstat(requestitem, &fstat);
        size= fstat.st_size;
    	
		fclose(item);
    	sprintf(stream,"HTTP/1.1 200 OK\r\n");
    	sprintf(stream,"%sServer: My_server \r\n",stream);
    	sprintf(stream,"%sContent-Length: %d\r\n",stream,size);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n",stream,contenttype);       
    }else{
    	sprintf(stream,"HTTP/1.1 404 Not Found\r\n");
    	sprintf(stream,"%sServer: My_server\r\n",stream);
    	sprintf(stream,"%sContent-Length: 20\r\n",stream);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n",stream,contenttype);
    	sprintf(stream,"%s\r\n",stream);
    	sprintf(stream,"%sDocument not found!\n",stream);
    }


    #endif

    #ifdef DEBUG
    
     
    FILE * item;
    	
    item = fopen(requestitem,"r");

    if(item!=NULL){
		fclose(item);
    	printf("HTTP/1.1 200 OK\r\n");
    	printf("Server: My_server \r\n");
    	printf("Content-Length: %d\r\n",30);
    	printf("Connection: %s\r\n",connection);
    	printf("Content-Type: %s\r\n",contenttype);       
    }else{
    	printf("HTTP/1.1 404 Not Found\r\n");
    	printf("Server: My_server\r\n");
    	printf("Content-Length: 20\r\n");
    	printf("Connection: %s\r\n",connection);
    	printf("Content-Type: %s\r\n",contenttype);
    	printf("\r\n");
    	printf("Document not found!\n");
    }

    #endif

}

void deleteOption(char * stream, char * connection,char * contenttype,char * requestitem){

    #ifndef DEBUG
   
	int errorflag;

	errorflag = remove(requestitem);

    if(errorflag == 0){
        sprintf(stream,"HTTP/1.1 204 No Content\r\n");
    	sprintf(stream,"%sServer: My_server\r\n",stream);
    	sprintf(stream,"%sContent-Length: 17\r\n",stream);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n",stream,contenttype);
    	sprintf(stream,"%s\r\n",stream);
    	sprintf(stream,"%sDocument deleted\n",stream);
    }else{
    	sprintf(stream,"HTTP/1.1 404 Not Found\r\n" );
    	sprintf(stream,"%sServer: My_server\r\n",stream);
    	sprintf(stream,"%sContent-Length: 20\r\n",stream);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n",stream,contenttype);
    	sprintf(stream,"%s\r\n",stream);
    	sprintf(stream,"%sDocument not found!\n",stream);

    }

    #endif

    #ifdef DEBUG
    
    int errorflag;

	errorflag = remove(requestitem);

    if(errorflag == 0){
        printf("HTTP/1.1 204 No Content\r\n");
    	printf("Server: My_server\r\n");
    	printf("Content-Length: 17\r\n");
    	printf("Connection: %s\r\n",connection);
    	printf("Content-Type: %s\r\n",contenttype);
    	printf("\r\n");
    	printf("Document deleted\n");
    }else{
    	printf("HTTP/1.1 404 Not Found\r\n" );
    	printf("Server: My_server\r\n");
    	printf("Content-Length: 20\r\n");
    	printf("Connection: %s\r\n",connection);
    	printf("Content-Type: %s\r\n",contenttype);
    	printf("\r\n");
    	printf("Document not found!\n");

    }

    #endif
}

void notImplementedOption(char *stream ,char * connection,char * contenttype){
   
        sprintf(stream,"HTTP/1.1 501 No Implemented\r\n");
    	sprintf(stream,"%sServer: My_server\r\n",stream);
    	sprintf(stream,"%sContent-Length: 23\r\n",stream);
    	sprintf(stream,"%sConnection: %s\r\n",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\r\n",stream,contenttype);
    	sprintf(stream,"%s\r\n",stream);
    	sprintf(stream,"%sMethod not implemented\n",stream);
}

void notAnOption(char* stream){
     
    sprintf(stream,"HTTP/1.1 406 Not Acceptable\r\n");

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
 enter = 0;
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
 enter = 0;
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
 enter = 0;
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
 enter = 0;
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
 enter = 0;
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





FILE *file=fopen("debug.txt","w");
printf("The file debug.txt is now recreated\n" );



}
#endif

