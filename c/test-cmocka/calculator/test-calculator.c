#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdbool.h>
#include "cmocka.h"

#include "calculator.h"


static void test_something(void **state)
{
    (void)state;  // unused variable

}


int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_something),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
