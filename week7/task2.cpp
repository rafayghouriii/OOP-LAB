#include<iostream>
#include<string>
using namespace std;

class Shape
{
protected:
    string shade;
    double posX;
    double posY;
    double outline;

public:
    Shape(string c, double a, double b, double bord) : shade(c), posX(a), posY(b), outline(bord) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape
{
    double radius;

public:
    Circle(string c, double a, double b, double bord, double rad) : Shape(c, a, b, bord), radius(rad) {}

    void draw() override
    {
        cout << "rendering a circle with color " << shade << " at coordinates (" << posX << ", " << posY << ")" << endl;
    }

    double calculateArea() override
    {
        return 3.1416 * radius * radius;
    }

    double calculatePerimeter() override
    {
        return 2 * 3.1416 * radius;
    }
};

class Rectangle : public Shape
{
    double height;
    double width;

public:
    Rectangle(string c, double a, double b, double bord, double w, double h) : Shape(c, a, b, bord), width(w), height(h) {}

    void draw() override
    {
        cout << "rendering a rectangle with color " << shade << " at coordinates (" << posX << ", " << posY << ")" << endl;
    }

    double calculateArea() override
    {
        return height * width;
    }

    double calculatePerimeter() override
    {
        return 2 * (height + width);
    }
};

int main()
{
    string colorCircle = "green", colorRect = "yellow";
    double xCircle = 2.5, yCircle = 3.1, borderCircle = 0.8, rad = 4.2;
    double xRect = 1.2, yRect = 2.8, borderRect = 0.7, wRect = 5.0, hRect = 7.5;

    Shape* shape = new Circle(colorCircle, xCircle, yCircle, borderCircle, rad);
    cout << "circle details:" << endl;
    shape->draw();
    cout << "area: " << shape->calculateArea() << endl;
    cout << "perimeter: " << shape->calculatePerimeter() << endl;
    delete shape;

    shape = new Rectangle(colorRect, xRect, yRect, borderRect, wRect, hRect);
    cout << "rectangle details:" << endl;
    shape->draw();
    cout << "area: " << shape->calculateArea() << endl;
    cout << "perimeter: " << shape->calculatePerimeter() << endl;
    delete shape;

    return 0;
}
