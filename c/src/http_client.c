#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "http_client.h"

Request* Request_create(char* name, char* email, char* subject, char* message) {
    Request* request = malloc(sizeof(*request));
    strncpy(request->name, name, sizeof(request->name) - 1);
    strncpy(request->email, email, sizeof(request->email) - 1);
    strncpy(request->subject, subject, sizeof(request->subject) - 1);
    strncpy(request->message, message, sizeof(request->message) - 1);

    return request;
}

Response* Response_create(int code)
{
    Response* response = malloc(sizeof(*response));
    response->code = code;

    return response;
}

bool http_client_post(Request* request, Response* response) {
    (void)request; // unused - this is a completely dummy implementation
    response->code = 200;
    return true;
}
