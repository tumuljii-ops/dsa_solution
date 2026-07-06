#include <iostream>
using namespace std;

// Function Template

template<typename T>

T maximum(T a, T b)
{
    if(a > b)
        return a;

    return b;
}

int main()
{
    cout << maximum(10,20) << endl;

    cout << maximum(3.5,6.2) << endl;

    cout << maximum('A','Z') << endl;
}