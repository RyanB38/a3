#include "ParkingMeter.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "IReceipt.h"
#include "ICalculateTime.h"
#include "StandardReceipt.h"


using namespace std;

ParkingMeter::ParkingMeter(ICalculateTime* strategy)
    : amountInCents(0), costStrategy(strategy), defaultReceipt() 
    {
        // using this keyword in order to set receipt strategy to point at the StandardReceipt defaultreceipt
        this->receiptStrategy = &this->defaultReceipt;
    }

ParkingMeter::ParkingMeter(ICalculateTime* strategy, IReceipt* receipt)
    : amountInCents(0), costStrategy(strategy), receiptStrategy(receipt) {}


void ParkingMeter::addPayment(int val) {
    if (val >= 0)
        amountInCents += val;
    else
        cerr << "Invalid payment amount." << endl;
}

void ParkingMeter::cancel() {
    amountInCents = 0;
}

int ParkingMeter::getAmount() {
    return amountInCents;
}

string ParkingMeter::printTicket() {
    if (!costStrategy) return "Error: No cost strategy set.";
    int minutes = costStrategy->calculateTime(amountInCents);
    // maintains simple polymorphism and raw PTRs instead of control flow
    return receiptStrategy->printReceipt(minutes);
}
