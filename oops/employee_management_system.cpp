#include <iostream>
#include <string>

using namespace std;

// ================= Parent Class =================

class Employee
{
protected:

    string name;
    int id;
    double salary;

public:

    // Default Constructor
    Employee()
    {
        cout << "Employee Constructor Called\n";
    }

    // Initialize common data
    void setData(string name, int id, double salary)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }

    // Same for every employee
    string getName() const
    {
        return name;
    }

    // Same for every employee
    int getId() const
    {
        return id;
    }

    // Different for every employee
    virtual double calculateSalary()
    {
        return salary;
    }

    // Different for every employee
    virtual void display()
    {
        cout << "\nEmployee Details\n";
        cout << "-------------------------\n";
        cout << "Name   : " << name << endl;
        cout << "ID     : " << id << endl;
        cout << "Salary : " << calculateSalary() << endl;
    }

    // Base class destructor should be virtual
    virtual ~Employee()
    {
        cout << "Employee Destructor Called\n";
    }
};

// ================= Manager Class =================

class Manager : public Employee
{
private:

    double bonus;

public:

    Manager(string name, int id, double salary, double bonus)
    {
        // Initialize parent data
        setData(name, id, salary);

        // Initialize child data
        this->bonus = bonus;

        cout << "Manager Constructor Called\n";
    }

    double calculateSalary() override
    {
        return salary + bonus;
    }

    void display() override
    {
        cout << "\nManager Details\n";
        cout << "-------------------------\n";
        cout << "Name   : " << name << endl;
        cout << "ID     : " << id << endl;
        cout << "Salary : " << calculateSalary() << endl;
        cout << "Bonus  : " << bonus << endl;
    }

    ~Manager()
    {
        cout << "Manager Destructor Called\n";
    }
};

// ================= Developer Class =================

class Developer : public Employee
{
private:

    double overtime;

public:

    Developer(string name, int id, double salary, double overtime)
    {
        // Initialize parent data
        setData(name, id, salary);

        // Initialize child data
        this->overtime = overtime;

        cout << "Developer Constructor Called\n";
    }

    double calculateSalary() override
    {
        return salary + overtime;
    }

    void display() override
    {
        cout << "\nDeveloper Details\n";
        cout << "-------------------------\n";
        cout << "Name      : " << name << endl;
        cout << "ID        : " << id << endl;
        cout << "Salary    : " << calculateSalary() << endl;
        cout << "Overtime  : " << overtime << endl;
    }

    ~Developer()
    {
        cout << "Developer Destructor Called\n";
    }
};

// ================= Main Function =================

int main()
{
    Employee *emp;

    cout << "\nCreating Manager\n\n";

    emp = new Manager("Rahul",101,50000,10000);

    emp->display();

    delete emp;

    cout << "\n===================================\n";

    cout << "\nCreating Developer\n\n";

    emp = new Developer("Tumul",102,70000,15000);

    emp->display();

    delete emp;

    return 0;
}