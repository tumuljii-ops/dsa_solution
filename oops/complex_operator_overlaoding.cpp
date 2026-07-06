#include <iostream>
using namespace std;

class Complex
{
private:

    double real;
    double imag;

public:

    // Constructor
    Complex(double real = 0, double imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }

    // Addition
    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real,
                       imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex &other)
    {
        return Complex(real - other.real,
                       imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex &other)
    {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;

        return Complex(newReal, newImag);
    }

    // Division
    Complex operator/(const Complex &other)
    {
        double denominator =
            other.real * other.real +
            other.imag * other.imag;

        double newReal =
            (real * other.real + imag * other.imag)
            / denominator;

        double newImag =
            (imag * other.real - real * other.imag)
            / denominator;

        return Complex(newReal, newImag);
    }

    // Equality
    bool operator==(const Complex &other)
    {
        return real == other.real &&
               imag == other.imag;
    }

    // Friend Function
    friend ostream& operator<<(ostream &out,
                               const Complex &c);
};

// Friend Function

ostream& operator<<(ostream &out,
                    const Complex &c)
{
    out << c.real
        << " + "
        << c.imag
        << "i";

    return out;
}

int main()
{
    Complex c1(4,2);
    Complex c2(1,3);

    Complex add = c1 + c2;

    Complex sub = c1 - c2;

    Complex mul = c1 * c2;

    Complex div = c1 / c2;

    cout << "Addition       : "
         << add << endl;

    cout << "Subtraction    : "
         << sub << endl;

    cout << "Multiplication : "
         << mul << endl;

    cout << "Division       : "
         << div << endl;

    if(c1 == c2)
    {
        cout << "Equal\n";
    }
    else
    {
        cout << "Not Equal\n";
    }

    return 0;
}