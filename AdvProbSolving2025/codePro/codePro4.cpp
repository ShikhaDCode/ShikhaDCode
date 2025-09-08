#include <iostream>
#include <string>

using namespace std;

// Function to convert time in HH:MM format to total minutes
int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int main() {
    string startTime, endTime;
    cin >> startTime >> endTime;

    // Convert start and end times to total minutes
    int startMinutes = timeToMinutes(startTime);
    int endMinutes = timeToMinutes(endTime);

    // Calculate usage duration
    int duration;
    if (endMinutes >= startMinutes) {
        duration = endMinutes - startMinutes;
    } else {
        duration = (24 * 60 - startMinutes) + endMinutes;
    }

    // Calculate the fee
    int fee = 500; // Minimum fee for up to 30 minutes
    if (duration > 30) {
        duration -= 30;
        fee += ((duration + 9) / 10) * 300; // Charge for every additional 10 minutes
    }

    // Cap the fee at 30,000
    if (fee > 30000) {
        fee = 30000;
    }

    cout << fee << endl;
    return 0;
}
