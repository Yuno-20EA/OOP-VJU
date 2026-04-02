#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Point {
public:
    double x,y;
    Point(double x  = 0,double y =0) : x(x), y(y)  {}
};

class Circle {
public:
    Point center;
    double radius;
    Circle (Point center, double radius) : center(center) {
        this->center = center;
        this->radius = radius;
    }
};

class Rectangle {
public:
    Point corner;
    double length,width;
    Rectangle (Point corner, double length, double width) : corner(corner) {
        this->corner = corner;
        this->length = length;
        this->width = width;
    }
};

double Distance(const  Point p1, const Point p2) {
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

bool point_in_circle(const Circle& circle,const Point& p) {
    return Distance(circle.center,p)<=circle.radius;
}

bool rect_in_circle(const Circle& circle,const Rectangle& rect) {
    Point bottom_left(rect.corner);
    Point bottom_right(rect.corner.x+rect.width,rect.corner.y);
    Point top_left(rect.corner.x,rect.corner.y+rect.length);
    Point top_right(rect.corner.x + rect.width, rect.corner.y + rect.length);

    if (!point_in_circle(circle, bottom_left) ||
        !point_in_circle(circle, top_left)    ||
        !point_in_circle(circle, top_right)   ||
        !point_in_circle(circle, bottom_right)) {
        return false;
        }
    else {
        return true;
    }
}

bool rect_circle_overlap(const Circle& circle,const Rectangle& rect) {
    double closest_x = clamp(circle.center.x, rect.corner.x, rect.corner.x + rect.width);
    double closest_y = clamp(circle.center.y, rect.corner.y, rect.corner.y + rect.length);
    Point closest_point=Point(closest_x,closest_y);
    return point_in_circle(circle,closest_point);
}

int main() {
    Circle circle(Point(150,100),75);

    Point p1(150,100);
    Point p2(300,300);
    cout<<"p1 trong vong tron: "<<(point_in_circle(circle,p1) ? "true" : "false")<<endl;
    cout<<"p2 trong vong tron:  "<<(point_in_circle(circle,p2) ? "true" : "false")<<endl;

    Rectangle rSmall(Point(140, 90),  10,  10);
    Rectangle rLarge(Point(100, 50), 300, 200);
    cout << "rSmall trong circle:   "<< (rect_in_circle(circle, rSmall) ? "true" : "false") << "\n";
    cout << "rLarge overlap circle: "<< (rect_circle_overlap(circle, rLarge) ? "true" : "false") << "\n";
}