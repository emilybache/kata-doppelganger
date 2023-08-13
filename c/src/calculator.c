#include "calculator.h"
#include "authorizer.h"

bool calculator_add(int left, int right, int *result)
{
    if (calculation_is_authorized()) {
        *result = left + right;
        return true;
    } else {
        return false;
    }
}
