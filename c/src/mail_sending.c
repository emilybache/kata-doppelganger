#include <stdlib.h>
#include <string.h>
#include "mail_sending.h"

User* User_create(char* name, char* email) {
    User* user = malloc(sizeof(*user));
    strncpy(user->name, name, sizeof(user->name) - 1);
    strncpy(user->email, email, sizeof(user->email) - 1);

    return user;
}



bool send_mail(User* user, char* message, Response *response) {
    char subject[MAX_NAME_LENGTH];
    strncpy(subject, "New notification", MAX_NAME_LENGTH - 1);

    // BUG - should be Request(user->name, user->email ...)
    Request* request = Request_create(user->email, user->name, subject, message);
    return http_client_post(request, response);
}
