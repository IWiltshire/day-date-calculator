#ifndef VALIDITY_H
#define VALIDITY_H

#include <iostream>

enum ValidityCheckResult {
    VALID,
    NOT_GREGORIAN,
    WRONG_FORMAT,
    INVALID_DATE
};

#endif
