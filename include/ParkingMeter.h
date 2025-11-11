#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include <string>
#include "ICalculateTime.h"
#include "IReceipt.h"
#include "StandardReceipt.h"

class ParkingMeter {
private:
    int amountInCents;
    ICalculateTime* costStrategy;
    IReceipt* receiptStrategy;
    StandardReceipt defaultReceipt;

public:
    ParkingMeter(ICalculateTime* strategy);
    ParkingMeter(ICalculateTime* strategy, IReceipt* receipt);
    void addPayment(int val);
    void cancel();
    int getAmount();
    std::string printTicket();
};

#endif
