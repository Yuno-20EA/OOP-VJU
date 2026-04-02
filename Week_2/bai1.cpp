#include <iostream>
#include <iomanip>


using namespace std;

int main() {
    int second = 60;
    int a = int (second * 42 + 42);
    cout << "1." << a << endl;

    double mile = 1.61 ;
    double b = double(10 / mile);
    cout << "2." << fixed <<setprecision(8)<< b << endl;

    double pace1 = double (b/a);
    cout << "3." << fixed << setprecision(8)<< pace1 << " mile/s" << endl;
    double pace2 = double (b / 42);
    cout << "  " << fixed << setprecision(8)<< pace2 << " mile/min" << endl;

    double pace3 = double (b / (a/60*60));
    cout << "  " << fixed << setprecision(8)<< pace3 << " mile/h" << endl;
}