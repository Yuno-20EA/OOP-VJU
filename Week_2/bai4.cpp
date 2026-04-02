#include <iostream>

using namespace std;

int main() {
    for (int i = 0;i<2;i++) {
        for (int j = 0;j<1;j++) {
            cout << "+ - - - -";
            cout << " +\n";
        }
        for (int k = 0;k<4;k++) {
            cout << "|        ";
            cout << " |\n";
        }
    }
    cout << "+ - - - -";
    cout << " +\n";
}