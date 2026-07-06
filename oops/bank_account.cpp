#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

//================ Parent Class =================

class Account
{
protected:

    int accountNumber;
    string holderName;
    double balance;

public:

    Account()
    {
        cout<<"Account Constructor Called\n";
    }

    void setData(int accountNumber,string holderName,double balance)
    {
        this->accountNumber = accountNumber;
        this->holderName = holderName;
        this->balance = balance;
    }

    // Same for every account
    void deposit(double amount)
    {
        if(amount<=0)
        {
            throw invalid_argument("Deposit amount must be positive.");
        }

        balance += amount;

        cout<<"Amount Deposited Successfully\n";
    }

    // Different for every account
    virtual void withdraw(double amount)
    {
        if(amount>balance)
        {
            throw runtime_error("Insufficient Balance.");
        }

        balance -= amount;

        cout<<"Amount Withdrawn Successfully\n";
    }

    // Different for every account
    virtual void display()
    {
        cout<<"\nAccount Details\n";
        cout<<"---------------------------\n";
        cout<<"Account Number : "<<accountNumber<<endl;
        cout<<"Holder Name    : "<<holderName<<endl;
        cout<<"Balance        : "<<balance<<endl;
    }

    virtual ~Account()
    {
        cout<<"Account Destructor Called\n";
    }

};

//================ Saving Account =================

class SavingAccount : public Account
{
private:

    double interestRate;

public:

    SavingAccount(int accountNumber,string holderName,double balance,double interestRate)
    {
        setData(accountNumber,holderName,balance);

        this->interestRate = interestRate;

        cout<<"Saving Account Constructor Called\n";
    }

    void display() override
    {
        cout<<"\nSaving Account\n";
        cout<<"---------------------------\n";
        cout<<"Account Number : "<<accountNumber<<endl;
        cout<<"Holder Name    : "<<holderName<<endl;
        cout<<"Balance        : "<<balance<<endl;
        cout<<"Interest Rate  : "<<interestRate<<" %"<<endl;
    }

    ~SavingAccount()
    {
        cout<<"Saving Account Destructor Called\n";
    }

};

//================ Current Account =================

class CurrentAccount : public Account
{
private:

    double overdraftLimit;

public:

    CurrentAccount(int accountNumber,string holderName,double balance,double overdraftLimit)
    {
        setData(accountNumber,holderName,balance);

        this->overdraftLimit = overdraftLimit;

        cout<<"Current Account Constructor Called\n";
    }

    void withdraw(double amount) override
    {
        if(amount > balance + overdraftLimit)
        {
            throw runtime_error("Overdraft Limit Exceeded.");
        }

        balance -= amount;

        cout<<"Amount Withdrawn Successfully\n";
    }

    void display() override
    {
        cout<<"\nCurrent Account\n";
        cout<<"---------------------------\n";
        cout<<"Account Number  : "<<accountNumber<<endl;
        cout<<"Holder Name     : "<<holderName<<endl;
        cout<<"Balance         : "<<balance<<endl;
        cout<<"Overdraft Limit : "<<overdraftLimit<<endl;
    }

    ~CurrentAccount()
    {
        cout<<"Current Account Destructor Called\n";
    }

};

//================ Main =================

int main()
{
    try
    {
        Account *acc;

        acc = new SavingAccount(101,"Tumul",50000,5);

        acc->deposit(10000);

        acc->withdraw(20000);

        acc->display();

        delete acc;

        cout<<"\n=============================\n";

        acc = new CurrentAccount(102,"Rahul",30000,10000);

        acc->withdraw(35000);

        acc->display();

        delete acc;

    }

    catch(const exception &e)
    {
        cout<<"\nException : "<<e.what()<<endl;
    }

}