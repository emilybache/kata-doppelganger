from calculator import Calculator


class StubAuthorizer:
    def __init__(self, stub_value):
        self.stub_value = stub_value

    def authorize(self):
        return self.stub_value


def test_divide_should_not_raise_any_error_when_authorized():
    calculator = Calculator(StubAuthorizer(True))
    assert calculator.divide(10, 2) == 5
