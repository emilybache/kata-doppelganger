#ifndef SAMPLE_MAIL_SENDING_H
#define SAMPLE_MAIL_SENDING_H

#include <stdbool.h>
#include "http_client.h"

typedef struct User {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} User;

User* User_create(char* name, char* email);

bool send_mail(User* user, char* message, Response *response);

#endif //SAMPLE_MAIL_SENDING_H
