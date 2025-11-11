#include "LinearCost.h"

LinearCost::LinearCost(int centsPerMinute)
    : centsPerMinute(centsPerMinute) {}

int LinearCost::calculateTime(int amountInCents) {
    return amountInCents / centsPerMinute;
}
