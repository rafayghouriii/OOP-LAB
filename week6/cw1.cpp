#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    protected:
        int accn;
        double balance;
    public:
        BankAccount(int an, double bal) : accn(an), balance(bal) {}
    
    void deposit(double dep)
    {
        balance += dep;
        cout << "deposited: $" << dep << " | new balance: $" << balance << endl;
    }
    
    void withdraw(double with)
    {
        if (with > balance)
        {
            cout << "insufficient funds!" << endl;
            return;
        }
        balance -= with;
        cout << "withdrawn: $" << with << " | new balance: $" << balance << endl;
    }
    
    double getBalance()
    {
        return balance;
    }
    
    int getAccountNumber()
    {
        return accn;
    }
    
    void checkBalance()
    {
        cout << "balance: " << balance << endl;
    }
};

class SavingAccount : public BankAccount
{
    const double monthinter;
    public:
        SavingAccount(int an, double bal, double mi) : BankAccount(an, bal), monthinter(mi) {}
    
    void applyInterest()
    {
        balance += balance * monthinter;
        cout << "interest applied! new balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overlimit;
    public:
        CheckingAccount(int an, double bal, double ol) : BankAccount(an, bal), overlimit(ol) {}
    
    void overdraft(double amt)
    {
        if (amt > overlimit)
        {
            cout << "overdraft limit exceeded!" << endl;
            return;
        }
        withdraw(amt);
    }
    
    void setOverlimit(double lim)
    {
        overlimit = lim;
    }
};

class BusinessAccount : public BankAccount
{
    const double tax;
    public:
        BusinessAccount(int an, double bal, double t) : BankAccount(an, bal), tax(t) {}
    
    void deposit(double amt)
    {
        double deductedamt = amt * tax;
        BankAccount::deposit(amt - deductedamt);
        cout << "corporate tax deducted: $" << deductedamt << endl;
    }
};

class Customer
{
    BankAccount* b;
    string name;
    public:
        Customer(BankAccount* bank, string n) : b(bank), name(n) {}
    
    void deposit(double amt)
    {
        b->deposit(amt);
    }
    
    void withdraw(double amt)
    {
        b->withdraw(amt);
    }
    
    void checkBalance()
    {
        b->checkBalance();
    }
};

class Employee
{
    protected:
        string name;
        int empid;
    public:
        Employee(string n, int e) : name(n), empid(e) {}
};

class Teller : public Employee
{
    BankAccount* b;
    public:
        Teller(BankAccount* bank, string n, int e) : b(bank), Employee(n, e) {}
    
    void deposit(double amt)
    {
        b->deposit(amt);
    }
    
    void withdraw(double amt)
    {
        b->withdraw(amt);
    }
    
    void checkBalance()
    {
        b->checkBalance();
    }
    
    void freeze()
    {
        cout << name << "'s account has been frozen!" << endl;
    }
};

class Manager : public Employee
{
    BankAccount* b;
    public:
        Manager(BankAccount* bank, string n, int e) : b(bank), Employee(n, e) {}
    
    void deposit(double amt)
    {
        b->deposit(amt);
    }
    
    
    
    void withdraw(double amt)
    {
        b->withdraw(amt);
    }
    
    void checkBalance()
    {
        b->checkBalance();
    }
    
    void freeze()
    {
        cout << name << "'s account has been frozen!" << endl;
    }
    
    void update(CheckingAccount* ch, double lim)
    {
        ch->setOverlimit(lim);
    }
};

int main()
{
    SavingAccount sAcc(101, 1000, 0.05);
    CheckingAccount cAcc(102, 500, 200);
    BusinessAccount bAcc(103, 3000, 0.10);
    Customer cust(&sAcc, "Alice");
    Teller teller(&cAcc, "Bob", 2);
    Manager manager(&bAcc, "Charlie", 3);
    cout << endl << "customer operations:" << endl;
    cust.deposit(200);
    cust.withdraw(100);
    cust.checkBalance();
    cout << endl << "teller operations:" << endl;
    teller.deposit(300);
    teller.withdraw(150);
    teller.checkBalance();
    teller.freeze();
    cout << endl << "manager operations:" << endl;
    manager.deposit(500);
    manager.withdraw(250);
    manager.checkBalance();
    manager.freeze();
    cout << endl << "applying interest for savings account:" << endl;
    sAcc.applyInterest();
    return 0;
}

