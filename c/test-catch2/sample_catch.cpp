#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
#include "calculator.h"
}


TEST_CASE ("Sample") {
    SECTION("sample section") {
        REQUIRE(true == false);
    }
}


