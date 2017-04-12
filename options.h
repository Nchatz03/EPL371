#ifndef _OPTIONS_H
#define _OPTIONS_H
void getOption(char * test,char * connection,char * contenttype,char * requestitem,char** buff,int*sizee);

void headOption(char * stream,char * connection,char * contenttype,char * requestitem) ; 

void deleteOption(char *stream,char * connection,char * contenttype,char  * requestitem) ;



void notImplementedOption(char * stream,char * connection,char * contenttype);

void notAnOption(char* stream);

#endif