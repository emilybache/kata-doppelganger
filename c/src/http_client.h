#ifndef SAMPLE_HTTP_CLIENT_H
#define SAMPLE_HTTP_CLIENT_H


#define MAX_NAME_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct Request {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char subject[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Request;

Request* Request_create(char* name, char* email, char* subject, char* message);

typedef struct Response {
    int code;
} Response;

Response* Response_create(int code);

bool http_client_post(Request* request, Response* response);

#endif //SAMPLE_HTTP_CLIENT_H
