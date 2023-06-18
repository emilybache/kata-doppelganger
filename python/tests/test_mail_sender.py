from mail_sender import MailSender


class ResponseCode:
    def __init__(self, code):
        self.code = code


class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email


class SpyHttpClient:
    def __init__(self, responses=None):
        self.mailbox = []
        self.responses = responses or [ResponseCode(200)]

    def post(self, url, request):
        response = self.responses.pop()
        if response.code != 503:
            self.mailbox.append((request.name, request.email))
        return response


def test_send_v1():
    http_client = SpyHttpClient()
    sender = MailSender(http_client)
    user1 = User("user1", "email1")
    sender.send_v1(user1, "hello1")
    assert ("user1", "email1") in http_client.mailbox


def test_send_v2():
    http_client = SpyHttpClient(responses=[ResponseCode(200), ResponseCode(503)])
    sender = MailSender(http_client)
    user1 = User("user1", "email1")
    response = sender.send_v2(user1, "hello1")
    assert response.code == 200
    assert ("user1", "email1") in http_client.mailbox
