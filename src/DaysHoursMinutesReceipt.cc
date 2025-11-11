#include "DaysHoursMinutesReceipt.h"
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

string DaysHoursMinutesReceipt::printReceipt(int minutes){
    const int day = 60*24;
    const int hour = 60;
    
    int totalDays = minutes / day;
    int totalHours = (minutes % day) / hour;
    int leftoverMinutes = (minutes % day) % hour;
    time_t now = time(0);
    char* formattedTime = ctime(&now);

    ostringstream out;
    out << setfill('-') << setw(48) << "" << endl;
    out << left << "RECEIPT" << endl;
    out << left << "The current time is: "<< formattedTime;
    if(totalDays > 0) {
        out << left << "Parking Time: " << totalDays << " days " << totalHours << " hours " << leftoverMinutes << " minutes"<< endl;
    } else{
        out << left << "Parking Time: " << totalHours << " hours " << leftoverMinutes << " minutes" << endl;
    }
    out << setfill('-') << setw(48) << "" << endl;
    return out.str();


}