
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double r;cin>>r;
    cout << "1." << fixed << setprecision(4) << double(4/3*(M_PI)*r*r) << endl;

    double a = 24.95 ;
    double b = a*(1-0.4) + 3;
    long long c = 75*59;
    cout << "2." << fixed << setprecision(2) << double (a + b) << " USD " << c << " CENT " << endl;

    int hour = 6;
    double minute = 52;

    double pace_easy = 8.25;
    double pace_tempo = 7.2;
    double total_run_time = pace_easy + (pace_tempo * 3) + pace_easy;

    minute += total_run_time;

    if (minute >= 60) {
        hour += static_cast<int>(minute) / 60;
        minute = (static_cast<int>(minute) % 60) + (minute - static_cast<int>(minute));
    }

    cout << "3." << hour << ":" << fixed << setprecision(0) << minute << " am" << endl;


}
