#include <cmath>
#include <iostream>
#include "Tuan4_Bai2.cpp"

using namespace std;

int main() {
    LineSegment dt1;
    LineSegment dt2(2,4,6,8);
    LineSegment dt3(4,5,7,9);
    LineSegment dt4(8,9,10,13);

    LineSegment arr[4] = {dt1,dt2,dt3,dt4};

    LineSegment maxLine = arr[0];
    LineSegment minLine = arr[0];

    cout << "Danh sach doan thang:" << endl;
    for(int i = 0; i < 4; i++) {
        cout << "dt" << i+1 << ": ";
        arr[i].display();
        cout << endl;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i].length()>maxLine.length()) {
            maxLine = arr[i];
        }
        else if (arr[i].length()<minLine.length()) {
            minLine = arr[i];
        }
    }
    cout << "\nDoan thang dai nhat: ";
    max.display();
    cout << endl;

    cout << "Doan thang ngan nhat: ";
    min.display();
    cout << endl;
}
