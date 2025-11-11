#include "StandardReceipt.h"
using namespace std;
string StandardReceipt::printReceipt(int minutes){
    time_t now = time(0);
    //  using C style array and the ctime library to create this recipet 
    char* formattedTime = ctime(&now);
    // creates a new ostring object in order for me to be able to use iomanip
    ostringstream out;
    out << setfill('-') << setw(48) << "" << endl;
    out << left << "RECEIPT" << endl;
    out << left << "The current time is: "<< formattedTime;
    out << left << "Parking Time: " << minutes << " minutes" << endl;
    out << setfill('-') << setw(48) << "" << endl;
    return out.str();
}
