#ifndef _OPTIONS_H
#define _OPTIONS_H

/** @brief GET option stream         
*
* This function implements the GET option that stream to the client. Checks if the 
* file exist. if the file exist send the stream to the client the 200 OK reply else 
* send the 404 Not Found reply. GET option includes the body of the file 
* 
* @param char* stream - the output stream
* @param char* connection - the connection status
* @param char* contenttype - the type of the requested item
* @param char* requestitem - the path of the requested item
*
* @return void.
*/
void getOption(char * stream,char * connection,char * contenttype,char * requestitem);

/** @brief HEAD option stream        
*
* This function implements the HEAD option that stream to the client. Checks if the 
* file exist. if the file exist send the stream to the client the 200 OK reply else 
* send the 404 Not Found reply. 
* 
* @param char* stream - the output stream
* @param char* connection - the connection status
* @param char* contenttype - the type of the requested item
* @param char* requestitem - the path of the requested item
*
* @return void.
*/
void headOption(char * stream,char * connection,char * contenttype,char * requestitem) ; 

/** @brief DELETE option stream          
*
* This function implements the DELETE option that stream to the client. Checks if the 
* file exist. if the file exist send the stream to the client the 204 No Content reply 
* to show that the file is deleted and no longer exist else send the 404 Not Found reply 
* 
* @param char* stream - the output stream
* @param char* connection - the connection status
* @param char* contenttype - the type of the requested item
* @param char* requestitem - the path of the requested item
*
* @return void.
*/
void deleteOption(char *stream,char * connection,char * contenttype,char  * requestitem) ;

/** @brief NOT IMPLEMENTED option stream           
*
* This function implements the NOT IMPLEMENTED option that stream to the client.
* If the option is not GET,HEAD or DELETE stream out the not implemented option 
* reply with code 501 Not Implemented.
*
* @param char* stream - the output stream
* @param char* connection - the connection status
* @param char* contenttype - the type of the requested item
*
* @return void.
*/
void notImplementedOption(char * stream,char * connection,char * contenttype);

/** @brief NOT AN OPTION option stream           
*
* This function implements the NOT AN OPTION option that stream to the client. 
* If the option is not one of the default server request stream out the 406 
* Not Acceptable reply to the client
* 
* @param char* stream - the output stream
*
* @return void.
*/
void notAnOption(char* stream);

#endif