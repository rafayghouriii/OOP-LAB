#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string accNumber, holderName, accType;
    double accBalance;

public:
    Account(string number, string name, string type, double balance)
        : accNumber(number), holderName(name), accType(type), accBalance(balance) {}

    virtual void deposit(double amount)
    {
        accBalance += amount;
        cout << "successfully deposited: " << amount << ". updated balance: " << accBalance << endl;
    }

    virtual bool withdraw(double amount)
    {
        if (amount > accBalance)
        {
            cout << "transaction failed: insufficient funds!" << endl;
            return false;
        }
        accBalance -= amount;
        cout << "successfully withdrawn: " << amount << ". updated balance: " << accBalance << endl;
        return true;
    }

    virtual double computeInterest()
    {
        return 0;
    }

    virtual void displayStatement()
    {
        cout << "account summary for " << holderName << endl;
        cout << "type: " << accType << ", available balance: " << accBalance << endl;
    }

    virtual void displayInfo()
    {
        cout << "account number: " << accNumber << endl;
        cout << "holder: " << holderName << endl;
        cout << "type: " << accType << endl;
        cout << "balance: " << accBalance << endl;
    }
};

class SavingsAccount : public Account
{
    double interestRate;
    double minBalance;

public:
    SavingsAccount(string number, string name, double balance, double rate, double minBal)
        : Account(number, name, "Savings", balance), interestRate(rate), minBalance(minBal) {}

    double computeInterest() override
    {
        return accBalance * (interestRate / 100);
    }

    bool withdraw(double amount) override
    {
        if (accBalance - amount < minBalance)
        {
            cout << "withdrawal denied: minimum balance must be maintained!" << endl;
            return false;
        }
        return Account::withdraw(amount);
    }

    void displayStatement() override
    {
        Account::displayStatement();
        cout << "interest rate: " << interestRate << "%, minimum required balance: " << minBalance << endl;
    }
};

class CheckingAccount : public Account
{
    double overdraftCap;

public:
    CheckingAccount(string number, string name, double balance, double overdraft)
        : Account(number, name, "Checking", balance), overdraftCap(overdraft) {}

    bool withdraw(double amount) override
    {
        if (accBalance - amount < -overdraftCap)
        {
            cout << "transaction failed: overdraft limit exceeded!" << endl;
            return false;
        }
        return Account::withdraw(amount);
    }

    void displayStatement() override
    {
        Account::displayStatement();
        cout << "overdraft limit: " << overdraftCap << endl;
    }
};

class FixedDepositAccount : public Account
{
    double fixedRate;
    int maturityYear;

public:
    FixedDepositAccount(string number, string name, double balance, double rate, int maturity)
        : Account(number, name, "Fixed Deposit", balance), fixedRate(rate), maturityYear(maturity) {}

    double computeInterest() override
    {
        return accBalance * (fixedRate / 100);
    }

    bool withdraw(double) override
    {
        cout << "withdrawal not permitted before maturity year: " << maturityYear << endl;
        return false;
    }

    void displayStatement() override
    {
        Account::displayStatement();
        cout << "fixed interest rate: " << fixedRate << "%, maturity year: " << maturityYear << endl;
    }
};

int main()
{
    string num1 = "SAV1001", num2 = "CHK2001", num3 = "FD3001";
    string name1 = "adam clark", name2 = "emma watson", name3 = "michael scott";
    
    SavingsAccount savings(num1, name1, 7000, 3.5, 2000);
    CheckingAccount checking(num2, name2, 4500, 800);
    FixedDepositAccount fixedDeposit(num3, name3, 15000, 6.2, 2030);

    cout << "\naccount information:\n";
    savings.displayInfo();
    checking.displayInfo();
    fixedDeposit.displayInfo();

    cout << "\nprocessing transactions:\n";
    savings.deposit(1800);
    savings.withdraw(5200);
    
    checking.withdraw(4700);
    checking.deposit(700);
    
    fixedDeposit.withdraw(3000);

    cout << "\nfinal statements:\n";
    savings.displayStatement();
    checking.displayStatement();
    fixedDeposit.displayStatement();

    return 0;
}

