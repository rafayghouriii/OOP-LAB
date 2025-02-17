#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Invoice {
    string pnum;
    string pdesc;
    int qty;
    double price;

public:
    Invoice(string num, string desc, int quan, double cost) {
        pnum = num;
        pdesc = desc;
        qty = (quan < 0) ? 0 : quan;
        price = (cost < 0) ? 0 : cost;
    }

    double getInvoiceAmount() {
        return qty * price;
    }
};

int main() {
    string pnum, pdesc;
    int quan;
    double price;

    cout << "enter product number: ";
    getline(cin, pnum);

    cout << "enter product description: ";
    getline(cin, pdesc);

    cout << "enter the quantity available: ";
    cin >> quan;

    cout << "enter the price of the product: ";
    cin >> price;

    Invoice h1(pnum, pdesc, quan, price);
    cout << "Invoice amount: " << h1.getInvoiceAmount() << endl;

    return 0;
}

