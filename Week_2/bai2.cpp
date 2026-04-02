#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    auto now = system_clock::now();
    long long total_s = duration_cast<seconds>(now.time_since_epoch()).count();

    long long gmt;cin>>gmt;

    long long total_s_gmt = total_s + (gmt * 3600);

    long long days = total_s_gmt / 86400;
    long long hours = total_s_gmt / 3600;
    long long minutes = (total_s_gmt ) / 60;

    cout << days << endl;
    cout << fixed << setprecision(12) << hours << endl;
    cout << fixed << setprecision(12) << minutes << endl;
    cout << total_s_gmt << endl;

}