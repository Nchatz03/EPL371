#include "options.h"


void getOption(char * servername,int contentlength,char * connection,char * contenttype,char * requestitem){

    FILE * item;
    char buff[10000000000];
    int code = 404; 
    item = fopen(requestitem,"r");

    if(item){
    	printf("HTTP/1.1 200 OK\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: %d\n",contentlength);
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	fscanf(fp,"%s",buff);
    	printf("%s\n",buff);
    	fclose(item);
        
    }else{
    	printf("HTTP/1.1 404 Not Found\n", );
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 20\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Document not found!\n");
    }

}

void headOption(char * servername,int contentlength,char * connection,char * contenttype,char * requestitem){
    
        FILE * item;
    	int code = 404; 
    	item = fopen(requestitem,"r");

	if(item){
		fclose(item);
    	printf("HTTP/1.1 200 OK\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: %d\n",contentlength);
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");

        
    }else{
    	printf("HTTP/1.1 404 Not Found\n", );
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 20\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Document not found!\n");
    }

}

void deleteOption(char * servername,int contentlength,char * connection,char * contenttype,,char * requestitem){

	int errorflag;

	errorflag = remove(requestitem);

    if(errorflag == 0){
        printf("HTTP/1.1 204 No Content\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: %d\n",contentlength);
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    }else{

    	printf("HTTP/1.1 404 Not Found\n", );
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 20\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Document not found!\n");

    }


}

void notImplementedOption(char * servername,char * connection,char * contenttype){

    if(errorflag == 0){
        printf("HTTP/1.1 501 No Implemented\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 24\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Method not implemented\n");

    }

}

void notAnOption(){

    printf("HTTP/1.1 406 Not Acceptable\n");

}

