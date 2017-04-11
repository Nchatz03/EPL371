#include "options.h"
#include "lib.h"

void getOption(char * test,char * connection,char * contenttype,char * requestitem){
  // printf("nikolas\n");


 //    sprintf(test, "HTTP/1.0 200 OK\r\n");    //line:netp:servestatic:beginserve
 //   	sprintf(test, "%sServer: Sysstatd Web Server\r\n", test);
 //   	sprintf(test, "%sContent-length: 211\r\n", test);
	// sprintf(test, "%sConnection: keep-alive\r\n", test);
	// sprintf(test, "%sContent-type: text/html\r\n\r\n", test);



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
    	sprintf(test, "HTTP/1.0 200 OK\r\n");
    	sprintf(test, "%sServer: My_server\r\n", test);
    	// printf("HTTP/1.1 200 OK\n");
    	// printf("Server: %s\n",servername);

    	sprintf(test, "%sContent-Length: %d\n\r",test,size);
    	sprintf(test,"%sConnection: %s\n\r",test,connection);
    	sprintf(test,"%sContent-Type: %s\n",test,contenttype);
    	//printf("\n");

    	
    	sprintf(test,"%s%s\n\r",test,buff);
    	fclose(item);
        
    }else{
    	sprintf(test,"HTTP/1.1 404 Not Found\n\r" );
    	sprintf(test,"%sServer: My_server\n\r",test);
    	sprintf(test,"%sContent-Length: 20\n\r",test);
    	sprintf(test,"%sConnection: %s\n\r",test,connection);
    	sprintf(test,"%sContent-Type: %s\n\r",test,contenttype);
    	// sprintf(test,"\n");
    	sprintf(test,"%sDocument not found!\n\r",test);
    }


    

}

void headOption(char * stream,char * connection,char * contenttype,char * requestitem){
    
        FILE * item;
    	
    	item = fopen(requestitem,"r");

	if(item!=NULL){
		fclose(item);
    	sprintf(stream,"HTTP/1.1 200 OK\n\r");
    	sprintf(stream,"%sServer: My_server \n\r",stream);
    	sprintf(stream,"%sContent-Length: %d\n",stream,30);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	//sprintf("\n");

        
    }else{
    	sprintf(stream,"HTTP/1.1 404 Not Found\n\r");
    	sprintf(stream,"%sServer: My_server\n\r",stream);
    	sprintf(stream,"%sContent-Length: 20\n\r",stream);
    	sprintf(stream,"%sConnection: %s\n\r",stream,connection);
    	sprintf(stream,"%sContent-Type: %s\n\r",stream,contenttype);
    	sprintf(stream,"%s\n\r",stream);
    	sprintf(stream,"%sDocument not found!\n\r",stream);
    }

}

void deleteOption(char * stream, char * connection,char * contenttype,char * requestitem){


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

