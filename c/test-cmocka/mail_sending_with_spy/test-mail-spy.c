#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdbool.h>
#include "cmocka.h"
#include <stdlib.h>
#include <string.h>
#include "mail_sending.h"


static void test_something(void **state)
{
    (void)state;  // unused variable

    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    strncpy(name, "name", MAX_NAME_LENGTH -1);
    strncpy(email, "email", MAX_NAME_LENGTH -1);
    strncpy(message, "message", MAX_MESSAGE_LENGTH -1);

    User* user = User_create(name, email);
    Response* response = Response_create(500);

    send_mail(user, message, response);

    // todo - check the right thing happens
}


int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_something),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
