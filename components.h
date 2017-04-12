#ifndef _COMPONENTS_H
#define _COMPONENTS_H

/** @brief Define the request         
*
* This function implements the definition of a request send from the 
* client to the server in order to reply. If the request option is not implemented
* server stream the default message 501 if the option is not exist or is wrong 
* server stream the message 406. if end is given communication close.
* 
* @param char* stream - the output stream
* @param char* requestoption - the option client request
* @param char* connection - the connection status
* @param char* contenttype - the type of the requested item
* @param char* requestitem - the path of the requested item
* @param char* body - the file body stream
*
* @return int - if request is get to multistream .
*/
int defineRequest(char* stream, char* requestoption, char* connection, char* contenttype, char* requestitem, char** body,int* size);

/** @brief Define the requestet item type        
*
* This function implements the definition of what type is the requested item type
* that client request 
* 
* @param char* extension - the file extension
* @param char** type - the request item type
*
* @return void.
*/
void defineContentType(char* extension , char** type);

#endif