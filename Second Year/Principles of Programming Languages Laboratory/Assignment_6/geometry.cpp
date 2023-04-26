#include <iostream>
#include <cmath>

using namespace std;

// Base class Shape
class Shape {
public:
    virtual float getArea() = 0; // Pure virtual function to calculate area
    virtual void display() = 0; // Pure virtual function to display shape information
};

// Circle class, derived from Shape
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float getArea() {
        return 3.1415 * pow(radius, 2); // Area of a circle: pi * r^2
    }

    void display() {
        cout << endl << "Circle: " << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
    }
};

// Triangle class, derived from Shape
class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    float getArea() {
        return 0.5 * base * height; // Area of a triangle: 0.5 * base * height
    }

    void display() {
        cout << endl << "Triangle: " << endl;
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << getArea() << endl;
    }
};

// Square class, derived from Shape
class Square : public Shape {
private:
    float side;

public:
    Square(float s) : side(s) {}

    float getArea() {
        return side * side; // Area of a square: side * side
    }

    void display() {
        cout << endl << "Square: " << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << getArea() << endl;
    }
};

// Polygon class, derived from Shape
class Polygon : public Shape {
protected:
    int numSides;
    float sideLength;

public:
    Polygon(int n, float l) : numSides(n), sideLength(l) {}

    float getArea() {
        // For simplicity, assuming all polygons are regular polygons
        // Area of regular polygon = (apothem * perimeter) / 2
        float apothem = (sideLength / 2) / tan(3.1415 / numSides);
        float perimeter = numSides * sideLength;
        return (apothem * perimeter) / 2;
    }

    void display() {
        cout << endl << "Polygon: " << endl;
        cout << "Number of sides: " << numSides << endl;
        cout << "Side length: " << sideLength << endl;
        cout << "Area: " << getArea() << endl;
    }
};

// Octagon class, derived from Polygon
class Octagon : public Polygon {
public:
    Octagon(float l) : Polygon(8, l) {}

    void display() {
        cout << endl << "Octagon: " << endl;
        cout << "Side length: " << sideLength << endl;
        cout << "Area: " << getArea() << endl;
    }
};

int main() {
    // Example usage of the shapes
    Circle c(5.0);
    c.display();

    Triangle t(3.0, 4.0);
    t.display();

    Square s(6.0);
    s.display();

    Polygon p(5, 7.0);
    p.display();

    Octagon o(8.0);
    o.display();

    return 0;
}
