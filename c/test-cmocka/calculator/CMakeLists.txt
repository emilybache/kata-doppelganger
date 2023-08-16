project(calculator-cmocka C)

add_cmocka_test(calculator_test
        SOURCES test-calculator.c
        LINK_LIBRARIES src cmocka-static)

add_cmocka_test_environment(calculator_test)



