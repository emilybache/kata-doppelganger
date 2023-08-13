project(calculator-cmocka C)

add_cmocka_test(calculator_test
        SOURCES test-calculator.c
        COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
        LINK_OPTIONS ${DEFAULT_LINK_FLAGS}
        LINK_LIBRARIES src cmocka-static)

add_cmocka_test_environment(calculator_test)



