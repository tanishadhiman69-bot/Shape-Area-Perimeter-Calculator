
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void calculate() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    float r;

    Circle(float x) {
        r = x;
    }

    void calculate() {
        cout << "Area = " << 3.14 * r * r << endl;
        cout << "Perimeter = " << 2 * 3.14 * r << endl;
    }
};

class Rectangle : public Shape {
public:
    float l, w;

    Rectangle(float x, float y) {
        l = x;
        w = y;
    }

    void calculate() {
        cout << "Area = " << l * w << endl;
        cout << "Perimeter = " << 2 * (l + w) << endl;
    }
};

class Triangle : public Shape {
public:
    float a, b, c;

    Triangle(float x, float y, float z) {
        a = x;
        b = y;
        c = z;
    }

    void calculate() {
        float s = (a + b + c) / 2;

        cout << "Area = "
             << sqrt(s * (s-a) * (s-b) * (s-c)) << endl;

        cout << "Perimeter = " << a + b + c << endl;
    }
};

int main() {
    Shape *s;

    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);

    int choice;

    cout << "===== Shape Calculator =====" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;

    cout << "Enter choice (1,2 or 3): ";
    cin >> choice;

    if (choice == 1) {
        s = &c;
    }
    else if (choice == 2) {
        s = &r;
    }
    else if (choice == 3) {
        s = &t;
    }
    else {
        cout << "Invalid choice! Please enter a number from 1 to 3.";
        return 0;
    }

    s->calculate();

    return 0;
}

