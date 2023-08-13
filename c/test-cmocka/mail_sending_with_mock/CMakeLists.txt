project(mail_sending-cmocka C)

add_cmocka_test(mail_sending_test
        SOURCES test-mail.c
        COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
        LINK_OPTIONS ${DEFAULT_LINK_FLAGS}
        LINK_LIBRARIES src cmocka-static)

add_cmocka_test_environment(mail_sending_test)

set_property(TARGET
        mail_sending_test
        PROPERTY
        LINK_FLAGS
        "${DEFAULT_LINK_FLAGS} -Wl,--wrap=http_client_post")

