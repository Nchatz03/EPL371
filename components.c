#include "components.h"

void defineRequest(char* requestOption,char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem){

char * requestOption;


if(strcmp(requestOption,"OPTIONS"){

   notImplementedOption(char * servername,int contentlength,char * connection,char * contenttype);

}
else if(strcmp(requestOption,"GET"){

   getOption(char * servername,int contentlength,,char * contenttype,char * requestitem);

}
else if(strcmp(requestOption,"HEAD"){

   headOption(char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem);

}
else if(strcmp(requestOption,"POST"){

   notImplementedOption(char * servername,int contentlength,char * connection,char * contenttype);

}
else if(strcmp(requestOption,"PUT"){

   notImplementedOption(char * servername,int contentlength,char * connection,char * contenttype);

}
else if(strcmp(requestOption,"DELETE"){

   deleteOption(char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem);

}
else if(strcmp(requestOption,"TRACE"){

   notImplementedOption(char * servername,int contentlength,char * connection,char * contenttype);

}
else if(strcmp(requestOption,"CONNECT"){

   notImplementedOption(char * servername,int contentlength,char * connection,char * contenttype);

}else if(strcmp(requestOption,"end"){

   exit(0);

else{

   notAnOption();
}

}

char* defineContentType(const char* extension){

    if (extension != NULL){
        if ((strcmp(extension, ".txt") || strcmp(extension, ".TXT")) == 0)
        {
            return "text/plain"; 
        }
        if ((strcmp(extension, ".sed") || strcmp(extension, ".SED")) == 0)
        {
            return "text/plain"; 
        }
        if ((strcmp(extension, ".awk") || strcmp(extension, ".AWK")) == 0)
        {
            return "text/plain";      
        }
        if ((strcmp(extension, ".c") || strcmp(extension, ".C")) == 0)
        {
            return "text/plain";      
        }
        if ((strcmp(extension, ".h") || strcmp(extension, ".H")) == 0)
        {
            return "text/plain";     
        }
        if ((strcmp(extension, ".jpeg") || strcmp(extension, ".JPEG")) == 0)
        {
            return "image/jpeg"; 
        }
        if ((strcmp(extension, ".jpg") || strcmp(extension, ".JPG")) == 0)
        {
            return "image/jpeg"; 
        }
        if ((strcmp(extension, ".gif") || strcmp(extension, ".GIF")) == 0)
        {
            return "image/gif"; 
        }
        if ((strcmp(extension, ".pdf") || strcmp(extension, ".PDF")) == 0)
        {
            return "application/pdf"; 
        }
        else
        {
            return "application/octet-stream"; 
        }
  
    }
    return NULL;
}

