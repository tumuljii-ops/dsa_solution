#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Student
{
private:

    string name;
    int rollNo;
    double cgpa;

    // Shared by all Student objects
    static int totalStudents;

public:

    // Constructor
    Student(string name, int rollNo, double cgpa)
    {
        // Using this pointer because parameter names
        // and data member names are same

        this->name = name;
        this->rollNo = rollNo;

        // Exception Handling
        if (cgpa < 0 || cgpa > 10)
        {
            throw invalid_argument("CGPA should be between 0 and 10.");
        }

        this->cgpa = cgpa;

        totalStudents++;

        cout << "Constructor Called for "
             << this->name << endl;
    }

    // Destructor
    ~Student()
    {
        totalStudents--;

        cout << "Destructor Called for "
             << name << endl;
    }

    // Getter Functions

    string getName() const
    {
        return name;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    double getCGPA() const
    {
        return cgpa;
    }

    // Setter Function

    void updateCGPA(double cgpa)
    {
        if (cgpa < 0 || cgpa > 10)
        {
            throw invalid_argument("Invalid CGPA");
        }

        this->cgpa = cgpa;
    }

    // Display Function

    void display() const
    {
        cout << "\nStudent Details\n";
        cout << "---------------------\n";
        cout << "Name     : " << name << endl;
        cout << "Roll No  : " << rollNo << endl;
        cout << "CGPA     : " << cgpa << endl;
    }

    // Operator Overloading

    bool operator==(const Student &other) const
    {
        return rollNo == other.rollNo;
    }

    // Static Member Function

    static void showTotalStudents()
    {
        cout << "\nTotal Students : "
             << totalStudents << endl;
    }

    // Friend Function

    friend ostream& operator<<(ostream &out, const Student &s);
};

// Static Variable

int Student::totalStudents = 0;

// Friend Function

ostream& operator<<(ostream &out, const Student &s)
{
    out << "\nStudent Details\n";
    out << "---------------------\n";
    out << "Name     : " << s.name << endl;
    out << "Roll No  : " << s.rollNo << endl;
    out << "CGPA     : " << s.cgpa << endl;

    return out;
}

int main()
{
    try
    {
        Student s1("Tumul",101,9.1);
        Student s2("Rahul",102,8.8);
        Student s3("Aman",101,9.5);

        // Member Function
        s1.display();

        // Friend Function
        cout << s2;

        // Operator Overloading
        if(s1 == s3)
        {
            cout << "\nBoth students have same Roll Number\n";
        }
        else
        {
            cout << "\nDifferent Students\n";
        }

        // Setter Function
        s1.updateCGPA(9.8);

        cout << "\nAfter Updating CGPA\n";

        cout << s1;

        // Static Function
        Student::showTotalStudents();

        // Uncomment to test exception

        // s2.updateCGPA(15);

    }

    catch(const exception &e)
    {
        cout << "\nException : "
             << e.what() << endl;
    }
}





