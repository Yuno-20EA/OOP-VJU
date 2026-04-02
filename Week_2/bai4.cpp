#include <iostream>

using namespace std;

void drawHorizontalLine(int cols, int cellWidth) {
    for (int i = 0; i < cols; i++) {
        cout << "+";
        for (int j = 0; j < cellWidth; j++) {
            cout << " -";
        }
        cout << " ";
    }
    cout << "+\n";
}

void drawVerticalLines(int cols, int cellWidth, int cellHeight) {
    for (int h = 0; h < cellHeight; h++) {
        for (int i = 0; i < cols; i++) {
            cout << "|";
            for (int j = 0; j < cellWidth; j++) {
                cout << "  ";
            }
            cout << " ";
        }
        cout << "|\n";
    }
}

int main() {
    int rows, cols;
    int cellWidth = 4;
    int cellHeight = 4;

    cout << "Nhap so hang: ";
    cin >> rows;
    cout << "Nhap so cot: ";
    cin >> cols;

    for (int r = 0; r < rows; r++) {
        drawHorizontalLine(cols, cellWidth);
        drawVerticalLines(cols, cellWidth, cellHeight);
    }

    drawHorizontalLine(cols, cellWidth);

    return 0;
}
