#include <stdio.h>
#include <errno.h>
#include <stdlib.h>



void getOption(char* header, char* result){
     char* p1=result;
    char* p=header;
    while(*p!=' '){
        *p1=*p;
        p1++;
        p++;
    }
    *p1='\0';
}

void getPath(char* header, char* result){
   char* p=header;
   char* p1=result;
   while(*p!='/'){
   	p++;
   }
   char*pp =p+1;
   while(*p!='.'){
   	p++;
   }
   while(*p!='/'){
   	p--;
   }
   char* ppp=p+1;
   while(pp!=ppp){
   	*result=*pp;
   	result++;
   	pp++;
   }
   *result='\0';
}

void getFileName(char* header, char* result){
  char* p=header;
   char* p1=result;
   while(*p!='.'){
   	p++;
   }
   while(*p!='/'){
   	p--;
   }
   p++;
   while(*p!=' ')
{
	*p1=*p;
	p1++;
	p++;
}
*p1='\0';
}



void getFileTYpe(char* header, char* result){
 char temp[20];
 getFileName(header,temp);
 char* p=temp;
 while(*p!='.'){
 	p++;
 } 
 // printf("%s",p);
   while(*p!='\0'){
   	*result=*p;
   	result++;
   	p++;
   }
   *result='\0';

}
int main(){


char * header="POST /dir/temp/index.txt HTP/1.1";
char option[25];
char path[25];
char filename[25];
char filetype[25];

getOption(header,option);
getPath(header,path);
getFileName(header,filename);
getFileTYpe(header,filetype);
printf("The header Is :%s\nThe Option Is :%s\nThe Path Is :%s\nThe File Name Is :%s\nThe File Type Is :%s",
	header,option,path,filename,filetype);

	return 0;
}