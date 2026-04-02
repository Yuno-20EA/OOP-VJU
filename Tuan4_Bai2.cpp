#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {
        this->x = p.x;
        this->y = p.y;
    }
    double getX() const { return x; }
    double getY() const { return y; }

    void display() const {
        cout << "[" << x << "," << y << "]";
    }
};

class LineSegment {
private:
    Point d1, d2;
public:
    LineSegment() : d1(8, 5), d2(1, 0) {}

    LineSegment(Point& p1, Point& p2) {
        this->d1 = p1;
        this->d2 = p2;
    }

    LineSegment(double x1, double y1, double x2, double y2) {
        this->d1 = Point(x1, y1);
        this->d2 = Point(x2, y2);
    }

    double length() const {
        return sqrt(pow(d1.getX() - d2.getX(), 2) + pow(d1.getY() - d2.getY(), 2));
    }

    void display() const {
        cout << "Tu diem ";
        d1.display();
        cout << " den ";
        d2.display();
        cout << " | Do dai: " << length() << endl;
    }
};
int main_odd(){
    LineSegment l1;
    l1.display();

    Point p1(2,3), p2(4,5);
    LineSegment l2(p1,p2);
    l2.display();

    LineSegment l3(2,4,6,8);
    l3.display();

    LineSegment l4(1,0,2,3);
    l4.display();
}
