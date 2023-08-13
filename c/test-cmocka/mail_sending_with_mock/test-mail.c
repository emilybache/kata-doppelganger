#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdbool.h>
#include "cmocka.h"
#include <stdlib.h>
#include <string.h>
#include "mail_sending.h"

bool __wrap_http_client_post(Request* request, Response* response);
bool __wrap_http_client_post(Request* request, Response* response) {
    check_expected(request);
    response->code = 200;
    return mock_type(bool);
}

int check_request(const LargestIntegralType actual_value, const LargestIntegralType expected_value);
int check_request(const LargestIntegralType actual_value, const LargestIntegralType expected_value) {
    Request* actual_request = (Request*)actual_value;
    Request* expected_request = (Request*)expected_value;

    if (
            strcmp(actual_request->name, expected_request->name) == 0 &&
            strcmp(actual_request->email, expected_request->email) == 0 &&
            strcmp(actual_request->subject, expected_request->subject) == 0 &&
            strcmp(actual_request->message, expected_request->message) == 0
    )   return 1;

    return 0;
}

static void test_send_one_user_with_mock(void **state)
{
    User* user;
    Request* expected_request;
    Response* response;
    bool success;
    int response_code = 500;
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char subject[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    (void)state;  // unused variable

    will_return(__wrap_http_client_post, true);

    strncpy(name, "name", MAX_NAME_LENGTH -1);
    strncpy(email, "email", MAX_NAME_LENGTH -1);
    strncpy(subject, "New notification", MAX_NAME_LENGTH -1);
    strncpy(message, "message", MAX_MESSAGE_LENGTH -1);

    user = User_create(name, email);
    response = Response_create(response_code);
    expected_request = Request_create(name, email, subject, message);

    expect_check(__wrap_http_client_post, request, check_request, expected_request);

    success = send_mail(user, message, response);
    assert_true(success);
    assert_int_equal(200, response->code);
}


int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_send_one_user_with_mock),
            };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
