#ifndef _COMPONENTS_H
#define _COMPONENTS_H

void defineRequest(char* requestOption,char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem);

void defineContentType( char* extension ,char** type);

#endif