#include "sample.h"

bool calculation_is_authorized(void) {
    return false;
}

bool calculator_add(int left, int right, int *result)
{
    if (calculation_is_authorized()) {
        *result = left + right;
        return true;
    }
    return false;
}
