#include<iostream>
#include<string>
using namespace std;

class Currency
{
protected:
    double value;
    int code;
    string notation;
    double exchangeRate;

public:
    Currency(double amt, int curCode, string symb, double rate) : value(amt), code(curCode), notation(symb), exchangeRate(rate) {}

    double convertToBase()
    {
        return value * exchangeRate;
    }

    virtual double convertTo(string target)
    {
        double baseAmount = convertToBase();
        double targetRate = 1.0;

        if (target == "USD") targetRate = 1.0;
        else if (target == "EUR") targetRate = 1.1;
        else if (target == "INR") targetRate = 0.012;
        else
        {
            cout << "Error: Exchange rate for " << target << " not available." << endl;
            return -1;
        }
        return baseAmount / targetRate;
    }

    virtual void showCurrency()
    {
        cout << value;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt, int curCode, string symb, double rate) : Currency(amt, curCode, symb, rate) {}

    double convertTo(string target) override
    {
        double baseAmount = convertToBase();
        double targetRate = 1.0;

        if (target == "EUR") targetRate = 1.1;
        else if (target == "INR") targetRate = 0.012;
        else
        {
            cout << "Error: Exchange rate for " << target << " not available." << endl;
            return -1;
        }
        return baseAmount / targetRate;
    }

    void showCurrency() override
    {
        cout << "Dollars: " << notation << value;
    }
};

class Euro : public Currency
{
public:
    Euro(double amt, int curCode, string symb, double rate) : Currency(amt, curCode, symb, rate) {}

    double convertTo(string target) override
    {
        double baseAmount = convertToBase();
        double targetRate = 1.0;

        if (target == "USD") targetRate = 1.0;
        else if (target == "INR") targetRate = 0.012;
        else
        {
            cout << "Error: Exchange rate for " << target << " not available." << endl;
            return -1;
        }
        return baseAmount / targetRate;
    }

    void showCurrency() override
    {
        cout << "Euros: " << notation << value;
    }
};

class PKR : public Currency
{
public:
    PKR(double amt, int curCode, string symb, double rate) : Currency(amt, curCode, symb, rate) {}

    double convertTo(string target) override
    {
        double baseAmount = convertToBase();
        double targetRate = 1.0;

        if (target == "USD") targetRate = 1.0;
        else if (target == "EUR") targetRate = 1.1;
        else
        {
            cout << "Error: Exchange rate for " << target << " not available." << endl;
            return -1;
        }
        return baseAmount / targetRate;
    }

    void showCurrency() override
    {
        cout << "Rupees: " << notation << value;
    }
};

int main()
{
    string symbolDollar = "$", symbolEuro = "€", symbolPkr = "Rs";
    double amountDollar = 120.5, amountEuro = 95.3, amountPkr = 15000;
    int codeDollar = 1, codeEuro = 2, codePkr = 3;
    double rateDollar = 1.0, rateEuro = 1.1, ratePkr = 0.0055;

    Dollar usd(amountDollar, codeDollar, symbolDollar, rateDollar);
    Euro eur(amountEuro, codeEuro, symbolEuro, rateEuro);
    PKR pkr(amountPkr, codePkr, symbolPkr, ratePkr);

    cout << "Original Currencies:\n";
    usd.showCurrency();
    cout << endl;
    eur.showCurrency();
    cout << endl;
    pkr.showCurrency();
    cout << endl << endl;

    cout << "Conversions:\n";
    cout << amountDollar << " USD to EUR: " << usd.convertTo("EUR") << " EUR\n";
    cout << amountDollar << " USD to INR: " << usd.convertTo("INR") << " INR\n";
    cout << amountEuro << " EUR to USD: " << eur.convertTo("USD") << " USD\n";
    cout << amountEuro << " EUR to INR: " << eur.convertTo("INR") << " INR\n";
    cout << amountPkr << " PKR to USD: " << pkr.convertTo("USD") << " USD\n";
    cout << amountPkr << " PKR to EUR: " << pkr.convertTo("EUR") << " EUR\n";

    return 0;
}

