#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdbool.h>
#include "cmocka.h"
#include <stdlib.h>
#include <string.h>
#include "mail_sending.h"


int check_request(const LargestIntegralType actual_value, const LargestIntegralType expected_value);
int check_request(const LargestIntegralType actual_value, const LargestIntegralType expected_value) {
    Request* actual_request = (Request*)actual_value;
    Request* expected_request = (Request*)expected_value;

    // todo: check the actual and expected match

    return 0;
}

static void test_something(void **state)
{
    User* user;
    Response* response;
    int response_code = 500;
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    (void)state;  // unused variable

    strncpy(name, "name", MAX_NAME_LENGTH -1);
    strncpy(email, "email", MAX_NAME_LENGTH -1);

    user = User_create(name, email);
    response = Response_create(response_code);

    send_mail(user, message, response);

    // todo - check the right thing happens
}

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_something),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
