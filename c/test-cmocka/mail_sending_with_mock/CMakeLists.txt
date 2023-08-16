project(mail_sending-cmocka C)

add_cmocka_test(mail_sending_test
        SOURCES test-mail.c
        LINK_LIBRARIES src cmocka-static)

add_cmocka_test_environment(mail_sending_test)



