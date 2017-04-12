#include "components.h"
#include "options.h"
#include "lib.h"


int defineRequest(char* stream, char* requestoption,char* connection,char* contenttype,char* requestitem,char** body,int *size){

    #ifndef DEBUG

    if(strcmp(requestoption,"") == 0){
		notAnOption(stream);
	}
    else if(strcmp(requestoption,"OPTIONS")==0){

        notImplementedOption(stream,connection,contenttype);
    }
    else if(strcmp(requestoption,"GET")==0){

   		getOption(stream,connection,contenttype,requestitem,body,size);
  		return 1;
	}
	else if(strcmp(requestoption,"HEAD")==0){

   		headOption(stream,connection,contenttype,requestitem);
	}
	else if(strcmp(requestoption,"POST")==0){

	    notImplementedOption(stream,connection,contenttype);
	}
	else if(strcmp(requestoption,"PUT")==0){

		notImplementedOption(stream,connection,contenttype);
	}
	else if(strcmp(requestoption,"DELETE")==0){

   		deleteOption( stream,connection,contenttype,requestitem);
	}
	else if(strcmp(requestoption,"TRACE")==0){

		notImplementedOption(stream,connection,contenttype);
	}
	else if(strcmp(requestoption,"CONNECT")==0){

		notImplementedOption(stream,connection,contenttype);
	}
	else if(strcmp(requestoption,"END")==0){

   		exit(0);
	}else{

		notAnOption(stream);
	}

	return 0;

	#endif

	#ifdef DEBUG



    if(strcmp(requestoption,"") == 0){
		printf("calling  -->   ");
		printf("notAnOption(stream);\n");
	}
    else if(strcmp(requestoption,"OPTIONS")==0){
        
        printf("calling  -->   ");
        printf("notImplementedOption(stream,connection,contenttype);\n");
    }
    else if(strcmp(requestoption,"GET")==0){

        printf("calling  -->   ");
   		printf("getOption(stream,connection,contenttype,requestitem,body);\n");
   		printf("return statement -->   ");
  		printf("return 1;\n");
  		return 1;
	}
	else if(strcmp(requestoption,"HEAD")==0){
        
        printf("calling  -->   ");
   		printf("headOption(stream,connection,contenttype,requestitem);\n");
	}
	else if(strcmp(requestoption,"POST")==0){

        printf("calling  -->   ");
	    printf("notImplementedOption(stream,connection,contenttype);\n");
	}
	else if(strcmp(requestoption,"PUT")==0){
        
        printf("calling  -->   ");
		printf("notImplementedOption(stream,connection,contenttype);\n");
	}
	else if(strcmp(requestoption,"DELETE")==0){
        
        printf("calling  -->   ");
   		printf("deleteOption( stream,connection,contenttype,requestitem);\n");
	}
	else if(strcmp(requestoption,"TRACE")==0){

        printf("calling  -->   ");
		printf("notImplementedOption(stream,connection,contenttype);\n");
	}
	else if(strcmp(requestoption,"CONNECT")==0){

        printf("calling  -->   ");
		printf("notImplementedOption(stream,connection,contenttype);\n");
	}
	else if(strcmp(requestoption,"END")==0){

        printf("calling  -->   ");
   		printf("exit(0);\n");
   		printf("CONNECTION TERMINATION REQUESTED \n");

	}else{

        printf("calling  -->   ");
		printf("notAnOption(stream);\n");
	}

    printf("return statement -->   ");
    printf("return 0;\n");
	return 0;

	#endif
}

void defineContentType( char* extension ,char** type){


        #ifndef DEBUG

	    if(strcmp(extension,"") == 0){
			exit(0);
	    }
        else if ((strcmp(extension, ".txt") && strcmp(extension, ".TXT")) == 0)
        {
            *type ="text/plain"; 
        }
         else if ((strcmp(extension, ".css") && strcmp(extension, ".CSS")) == 0)
        {
            *type = "text/css"; 
        }
        else if ((strcmp(extension, ".sed") && strcmp(extension, ".SED")) == 0)
        {
            *type = "text/plain"; 
        }
         else if ((strcmp(extension, ".html") && strcmp(extension, ".HTML")) == 0)
        {
            *type = "text/html"; 
        }
        else if ((strcmp(extension, ".htm") && strcmp(extension, ".HTM")) == 0)
        {
            *type = "text/html"; 
        }
        else if ((strcmp(extension, ".awk") && strcmp(extension, ".AWK")) == 0)
        {
            *type = "text/plain";      
        }
        else if ((strcmp(extension, ".c") && strcmp(extension, ".C")) == 0)
        {
            *type = "text/plain";      
        }
        else if ((strcmp(extension, ".h") && strcmp(extension, ".H")) == 0)
        {
            *type = "text/plain";     
        }
        else if ((strcmp(extension, ".jpeg") && strcmp(extension, ".JPEG")) == 0)
        {
            *type = "image/jpeg"; 
        }
        else if ((strcmp(extension, ".jpg") && strcmp(extension, ".JPG")) == 0)
        {
            *type = "image/jpeg"; 
        }
        else if ((strcmp(extension, ".gif") && strcmp(extension, ".GIF")) == 0)
        {
            *type = "image/gif"; 
        }
        else if ((strcmp(extension, ".pdf") && strcmp(extension, ".PDF")) == 0)
        {
            *type = "application/pdf"; 
        }
        else
        {
            *type = "application/octet-stream"; 
        }

        #endif

        #ifdef DEBUG


	    if(strcmp(extension,"") == 0){
			printf("exit(0)\n");
	    }
        if ((strcmp(extension, ".txt") && strcmp(extension, ".TXT")) == 0)
        {
            printf("text/plain \n"); 
        }
        else if ((strcmp(extension, ".sed") && strcmp(extension, ".SED")) == 0)
        {
            printf("text/plain \n");; 
        }
         else if ((strcmp(extension, ".html") && strcmp(extension, ".HTML")) == 0)
        {
            printf("text/html \n"); 
        }
        else if ((strcmp(extension, ".htm") && strcmp(extension, ".HTM")) == 0)
        {
            printf("text/html \n");  
        }
        else if ((strcmp(extension, ".awk") && strcmp(extension, ".AWK")) == 0)
        {
            printf("text/plain \n");     
        }
        else if ((strcmp(extension, ".c") && strcmp(extension, ".C")) == 0)
        {
            printf("text/plain \n");      
        }
        else if ((strcmp(extension, ".h") && strcmp(extension, ".H")) == 0)
        {
            printf("text/plain \n");     
        }
        else if ((strcmp(extension, ".jpeg") && strcmp(extension, ".JPEG")) == 0)
        {
            printf("image/jpeg \n");  
        }
        else if ((strcmp(extension, ".jpg") && strcmp(extension, ".JPG")) == 0)
        {
            printf("image/jpeg \n");   
        }
        else if ((strcmp(extension, ".gif") && strcmp(extension, ".GIF")) == 0)
        {
            printf("image/gif \n");  
        }
        else if ((strcmp(extension, ".pdf") && strcmp(extension, ".PDF")) == 0)
        {
            printf("application/pdf \n"); 
        }
        else
        {
            printf("application/octet-stream\n"); 
        }

        #endif

}

#ifdef DEBUG

/* Declaring Object Unit tests */
int main(){
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                     THIS IS A DEBUGGING CALL FOR COMPONENTS.c                                     |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|int defineRequest(char* stream,char* requestoption,char* connection,char* contenttype,char* requestitem,char* body)|\n");
printf("|                                               TESTING FOR EXCEPTIONS                                              |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|TESTING CHAR* REQUESTOPTION PARSING                                                                                |\n");
printf("|                                                                                                                   |\n");
printf("|1st try: OPTIONS                                                                                                   |\n");
printf("|2nd try: GET                                        													            |\n");
printf("|3rd try: HEAD                                                      											    |\n");
printf("|4th try: POST                                           												            |\n");
printf("|5th try: PUT                                                                                                       |\n");
printf("|6th try: DELETE                                                                                                    |\n");
printf("|7th try: TRACE                                                                                                     |\n");
printf("|8th try: CONNECT                                                                                                   |\n");
printf("|9th try: END                                                                                                       |\n");
printf("|10th try: NULL                                                                                                     |\n");
printf("|11th try: (space)GET                                                                                               |\n");
printf("|12th try: NOTOPTION                                                                                                |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                 1ST TRY : OPTIONS                                                 |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {OPTIONS}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
int returnflag =0;
char* stream = NULL;
char* requestoption = "OPTIONS";
char* connection = "TEST MODE";
char* contenttype = "TEST MODE";
char* requestitem = "debug.txt";
char* body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                    2ND TRY : GET                                                  |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {GET}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "GET";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                     3RD TRY: HEAD                                                 |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {HEAD}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "HEAD";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                    4TH TRY: POST                                                  |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {POST}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "POST";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                     5TH TRY: PUT                                                  |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {PUT}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "PUT";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                   6TH TRY: DELETE                                                 |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {DELETE}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "DELETE";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                    7TH TRY: TRACE                                                 |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {TRACE}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "TRACE";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                   8TH TRY: CONNECT                                                |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {CONNECT}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "CONNECT";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                    9TH TRY: END                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {END}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "END";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                   10TH TRY: NULL                                                  |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = NULL\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                 11TH TRY: (space)GET                                              |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = { GET}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = " GET";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                12TH TRY: NOTOPTION                                                |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("int returnflag = -1;\n");
printf("char* stream = NULL \n");
printf("char requestoption = {NOTOPTION}\n");
printf("char* connection = {static testing mode}\n");
printf("char* contenttype = {static testing mode}\n");
printf("char* requestitem = {debug.txt}\n");
printf("char* body = {static testing mode}\n");
/* Declaring Object Unit tests */
stream = NULL;
requestoption = "NOTOPTION";
connection = "TEST MODE";
contenttype = "TEST MODE";
requestitem = "debug.txt";
body = "TEST MODE";
returnflag = defineRequest(stream,requestoption,connection,contenttype,requestitem,body);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }








printf("\n");
printf("\n");
printf("*********************************************************************************************************************\n");
printf("*********************************************************************************************************************\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                void defineContentType( char* extension ,char** type)                              |\n");
printf("|                                               TESTING FOR EXCEPTIONS                                              |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|TESTING CHAR* REQUESTOPTION PARSING                                                                                |\n");
printf("|                                                                                                                   |\n");
printf("|1st try: .txt                                                                                                   |\n");
printf("|2nd try: .sed                                        													            |\n");
printf("|3rd try: .html                                                      											    |\n");
printf("|4th try: .htm                                          												            |\n");
printf("|5th try: .awk                                                                                                       |\n");
printf("|6th try: .c                                                                                                    |\n");
printf("|7th try: .h                                                                                                     |\n");
printf("|8th try: .jpeg                                                                                                   |\n");
printf("|9th try: .jpg                                                                                                       |\n");
printf("|10th try: .gif                                                                                                     |\n");
printf("|11th try: .pdf                                                                                               |\n");
printf("|12th try: .otherext                                                                                                |\n");
printf("|13th try: NULL                                                                                                |\n");
printf("|14th try: .PDF                                                                                                |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                   1ST TRY: .txt                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.txt} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
char * extension = ".txt";
char * type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                   2ND TRY: .sed                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.sed} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".sed";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  3RD TRY: .html                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.html} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".html";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  4TH TRY: .htm                                                    |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.htm} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".htm";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  5TH TRY: .awk                                                    |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.awk} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".awk";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                    6TH TRY: .c                                                    |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.c} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".c";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                    7TH TRY: .h                                                    |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.h} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".h";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  8TH TRY: .jpeg                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.jpeg} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".jpeg";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                   9TH TRY: .jpg                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.jpg} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".jpg";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  10TH TRY: .gif                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.gif} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".gif";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  11TH TRY: .pdf                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.pdf} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".pdf";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                              12TH TRY: .otherext                                                  |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.otherext} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".otherext";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                 13TH TRY: NULL                                                    |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = NULL \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = "";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                  14TH TRY: .PDF                                                   |\n");
printf("|-------------------------------------------------------------------------------------------------------------------|\n");
printf("\n");
printf("\n");
printf("/* Declaring Object Unit tests */\n");
printf("char* extension = {.PDF} \n");
printf("char* type = {type}\n");
/* Declaring Object Unit tests */
extension = ".PDF";
type = "TEST MODE";
defineContentType(extension,&type);
printf("\n");
printf("\n");
printf("\n");
printf("Press enter to continue\n");
enter = 0;
while (enter != '\r' && enter != '\n') { enter = getchar(); }



}
#endif

