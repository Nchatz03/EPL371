#include "options.h"
#include "lib.h"

void getOption(char * connection,char * contenttype,char * requestitem){
  // printf("nikolas\n");


 //    sprintf(test, "HTTP/1.0 200 OK\r\n");    //line:netp:servestatic:beginserve
 //   	sprintf(test, "%sServer: Sysstatd Web Server\r\n", test);
 //   	sprintf(test, "%sContent-length: 211\r\n", test);
	// sprintf(test, "%sConnection: keep-alive\r\n", test);
	// sprintf(test, "%sContent-type: text/html\r\n\r\n", test);




    


;


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
    	printf("HTTP/1.1 200 OK\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: %d\n",size);
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");

    	
    	printf("%s\n",buff);
    	fclose(item);
        
    }else{
    	printf("HTTP/1.1 404 Not Found\n" );
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
    	
    	item = fopen(requestitem,"r");

	if(item!=NULL){
		fclose(item);
    	printf("HTTP/1.1 200 OK\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: %d\n",contentlength);
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");

        
    }else{
    	printf("HTTP/1.1 404 Not Found\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 20\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Document not found!\n");
    }

}

void deleteOption(char * servername,int contentlength,char * connection,char * contenttype,char * requestitem){


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

    	printf("HTTP/1.1 404 Not Found\n" );
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 20\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Document not found!\n");

    }


}

void notImplementedOption(char * servername,char * connection,char * contenttype){
    
        printf("HTTP/1.1 501 No Implemented\n");
    	printf("Server: %s\n",servername);
    	printf("Content-Length: 24\n");
    	printf("Connection: %s\n",connection);
    	printf("Content-Type: %s\n",contenttype);
    	printf("\n");
    	printf("Method not implemented\n");

    

}

void notAnOption(){

    printf("HTTP/1.1 406 Not Acceptable\n");

}

