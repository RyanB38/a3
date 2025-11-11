#ifndef DAYSHOURSMINUTESRECEIPT_H
#define DAYSHOURSMINUTESRECEIPT_H
#include "IReceipt.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <sstream>
class DaysHoursMinutesReceipt : public IReceipt{
    public:
    std::string printReceipt(int minutes) override;
};
#endif