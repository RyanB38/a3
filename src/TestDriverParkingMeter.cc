#include <iostream>
#include <cassert>
#include "LinearCost.h"
#include "ProgressiveCost.h"
#include "ParkingMeter.h"
#include "StandardReceipt.h"
#include "DaysHoursMinutesReceipt.h"

using namespace std;

// Simple unit test suite
void runTests() {
    LinearCost linear(2);
    ProgressiveCost progressive(100, 2, 4);

    // Test LinearCost
    assert(linear.calculateTime(100) == 50);

    // Test ProgressiveCost
    assert(progressive.calculateTime(200) == 75);

    // Test ParkingMeter + cancel
    ParkingMeter meter(&linear);
    meter.addPayment(150);
    assert(meter.getAmount() == 150);
    meter.cancel();
    assert(meter.getAmount() == 0);

    // Test StandardReceipt formatting (minutes)
    {
        StandardReceipt receipt;
        ParkingMeter m(&linear, &receipt);
        m.addPayment(150); // with 2 cents/min -> 75 minutes
        std::string ticket = m.printTicket();
        // Contains minutes-based text
        assert(ticket.find("Parking Time: 75 minutes") != std::string::npos);
    }

    // Test DaysHoursMinutesReceipt formatting
    {
        DaysHoursMinutesReceipt receipt;
        ParkingMeter m(&linear, &receipt);
        // 2 cents/min: add 3000 cents -> 1500 minutes = 1 day 1 hour 0 minutes
        m.addPayment(3000);
        std::string ticket = m.printTicket();
        assert(ticket.find("Parking Time: 1 days 1 hours 0 minutes") != std::string::npos);
    }

    // Test ProgressiveCost + StandardReceipt formatting
    {
        StandardReceipt receipt;
        ParkingMeter m(&progressive, &receipt);
        // Progressive(100,2,4): 250 cents -> (100/2)=50 + (150/4)=37 -> 87 minutes
        m.addPayment(250);
        std::string ticket = m.printTicket();
        assert(ticket.find("Parking Time: 87 minutes") != std::string::npos);
    }

    // Test ProgressiveCost + DaysHoursMinutesReceipt formatting
    {
        DaysHoursMinutesReceipt receipt;
        ParkingMeter m(&progressive, &receipt);
        // Progressive(100,2,4): 250 cents -> 87 minutes -> 1 hours 27 minutes
        m.addPayment(250);
        std::string ticket = m.printTicket();
        assert(ticket.find("Parking Time: 1 hours 27 minutes") != std::string::npos);
    }

    cout << "[PASS] All unit tests passed successfully.\n";
}

int main() {
    runTests();

    LinearCost linear(2);
    ProgressiveCost progressive(100, 2, 4);

    StandardReceipt stdReceipt;
    DaysHoursMinutesReceipt dhmReceipt;

    ParkingMeter m1(&linear, &stdReceipt);
    m1.addPayment(150);
    cout << m1.printTicket() << endl;

    ParkingMeter m2(&progressive, &dhmReceipt);
    m2.addPayment(250);
    cout << m2.printTicket() << endl;

    return 0;
}