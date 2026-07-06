#include <iostream>
using namespace std;

//================ Parent Class ==================

class Shape
{
public:

    // Pure Virtual Function
    virtual double area() = 0;

    // Virtual Function
    virtual void display()
    {
        cout << "Area = " << area() << endl;
    }

    // Virtual Destructor
    virtual ~Shape()
    {
        cout << "Shape Destructor Called\n";
    }
};

//================ Circle ==================

class Circle : public Shape
{
private:

    double radius;

public:

    Circle(double radius)
    {
        this->radius = radius;
    }

    double area() override
    {
        return 3.14 * radius * radius;
    }

    void display() override
    {
        cout << "\nCircle\n";
        cout << "Radius = " << radius << endl;
        cout << "Area = " << area() << endl;
    }

    ~Circle()
    {
        cout << "Circle Destructor Called\n";
    }
};

//================ Rectangle ==================

class Rectangle : public Shape
{
private:

    double length;
    double breadth;

public:

    Rectangle(double length,double breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    double area() override
    {
        return length * breadth;
    }

    void display() override
    {
        cout << "\nRectangle\n";
        cout << "Length = " << length << endl;
        cout << "Breadth = " << breadth << endl;
        cout << "Area = " << area() << endl;
    }

    ~Rectangle()
    {
        cout << "Rectangle Destructor Called\n";
    }
};

//================ Triangle ==================

class Triangle : public Shape
{
private:

    double base;
    double height;

public:

    Triangle(double base,double height)
    {
        this->base = base;
        this->height = height;
    }

    double area() override
    {
        return 0.5 * base * height;
    }

    void display() override
    {
        cout << "\nTriangle\n";
        cout << "Base = " << base << endl;
        cout << "Height = " << height << endl;
        cout << "Area = " << area() << endl;
    }

    ~Triangle()
    {
        cout << "Triangle Destructor Called\n";
    }
};

//================ Main ==================

int main()
{
    Shape *shape;

    shape = new Circle(5);

    shape->display();

    delete shape;

    cout << "\n=========================\n";

    shape = new Rectangle(10,5);

    shape->display();

    delete shape;

    cout << "\n=========================\n";

    shape = new Triangle(8,6);

    shape->display();

    delete shape;
}