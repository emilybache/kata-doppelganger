project(mail_sending-spy-cmocka C)

add_cmocka_test(mail_sending_spy_test
        SOURCES test-mail-spy.c
        LINK_LIBRARIES src cmocka-static)

add_cmocka_test_environment(mail_sending_spy_test)

set_property(TARGET
        mail_sending_spy_test
        PROPERTY
        LINK_FLAGS
        "${DEFAULT_LINK_FLAGS} -Wl,--wrap=http_client_post")

