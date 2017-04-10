#ifndef _OPTIONS_H
#define _OPTIONS_H

void getOption(char * servername,int contentlength,,char * contenttype,char * requestitem) ;

void headOption(char * servername,int contentlength,char * connection,char * contenttype,char * requestitem) ; 

void deleteOption(char * servername,int contentlength,char * connection,char * contenttype,char  * requestitem) ;

void notImplementedOption(char * servername,int contentlength,char * connection,char * contenttype); 

void notAnOption();

#endif