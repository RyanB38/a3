#ifndef LINEARCOST_H
#define LINEARCOST_H

#include "ICalculateTime.h"

class LinearCost : public ICalculateTime {
private:
    int centsPerMinute;
public:
    LinearCost(int centsPerMinute = 2);
    int calculateTime(int amountInCents);
};

#endif
