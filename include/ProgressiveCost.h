#ifndef PROGRESSIVECOST_H
#define PROGRESSIVECOST_H
#include <algorithm>
#include "ICalculateTime.h"
class ProgressiveCost : public ICalculateTime{
    private:
    int highRate, lowRate, thresholdCents;
    
    public:
    // Parameterized Constructor
    ProgressiveCost(int thresholdCents, int lowRate, int highRate);
    // overridden time calculation
    int calculateTime(int amountInCents) override;
};
#endif
