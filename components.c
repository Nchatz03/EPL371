#include "components.h"
#include "options.h"
#include "lib.h"
// void defineRequest(char* requestOption,char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem){



// if(strcmp(requestOption,"OPTIONS")){

// notImplementedOption( servername,  connection,contenttype);
// }
// else if(strcmp(requestOption,"GET")){

//    getOption(servername, contentlength, connection,contenttype, requestitem);

// }
// else if(strcmp(requestOption,"HEAD")){

//    headOption( servername, contentlength, connection, contenttype, requestitem);

// }
// else if(strcmp(requestOption,"POST")){

//    notImplementedOption( servername,  connection,contenttype);

// }
// else if(strcmp(requestOption,"PUT")){

// notImplementedOption( servername,  connection,contenttype);}
// else if(strcmp(requestOption,"DELETE")){

//    deleteOption( servername, contentlength, connection, contenttype, requestitem);

// }
// else if(strcmp(requestOption,"TRACE")){

// notImplementedOption( servername,  connection,contenttype);
// }
// else if(strcmp(requestOption,"CONNECT")){

// notImplementedOption( servername,  connection,contenttype);
// }else if(strcmp(requestOption,"end")){

//    exit(0);

// }else{

//    notAnOption();
// }

// }

void defineContentType( char* extension ,char** type){

    // if (extension != NULL){
        if (     (strcmp(extension, ".txt") && strcmp(extension, ".TXT")    ) == 0)
        {
            *type ="text/plain"; 
        }
        else if ((strcmp(extension, ".sed") && strcmp(extension, ".SED")) == 0)
        {
            *type = "text/plain"; 
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
  
    // }
    // *type = "NO";
}

