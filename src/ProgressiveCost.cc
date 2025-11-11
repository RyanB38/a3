#include "ProgressiveCost.h"
// Parameterized constructor
ProgressiveCost::ProgressiveCost(int thresholdCents, int lowRate, int highRate)
    : thresholdCents(thresholdCents), lowRate(lowRate), highRate(highRate) {}
// overidden calculate time function
int ProgressiveCost::calculateTime(int amountInCents){
    int min1 = std::min(amountInCents, thresholdCents) / lowRate;
    int min2 = std::max(0, amountInCents - thresholdCents) / highRate;
    return min1 + min2;
}