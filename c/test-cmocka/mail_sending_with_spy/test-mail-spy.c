#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdbool.h>
#include "cmocka.h"
#include <stdlib.h>
#include <string.h>
#include "mail_sending.h"

Request *actual_request;

bool __wrap_http_client_post(Request* request, Response* response);
bool __wrap_http_client_post(Request* request, Response* response) {
    actual_request = request;
    response->code = 200;
    return mock_type(bool);
}

static void test_send_one_user_with_spy(void **state)
{
    (void)state;  // unused variable

    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char subject[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    will_return(__wrap_http_client_post, true);

    strncpy(name, "name", MAX_NAME_LENGTH -1);
    strncpy(email, "email", MAX_NAME_LENGTH -1);
    strncpy(subject, "New notification", MAX_NAME_LENGTH -1);
    strncpy(message, "message", MAX_MESSAGE_LENGTH -1);

    User* user = User_create(name, email);
    Response* response = Response_create(500);

    send_mail(user, message, response);

    assert_string_equal(actual_request->name, name);
    assert_string_equal(actual_request->email, email);
    assert_string_equal(actual_request->subject, subject);
    assert_string_equal(actual_request->message, message);
}




int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_send_one_user_with_spy),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
