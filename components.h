#ifndef _COMPONENTS_H
#define _COMPONENTS_H

void defineRequest(char* requestOption,char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem);

char* defineContentType(const char* extension);

#endif