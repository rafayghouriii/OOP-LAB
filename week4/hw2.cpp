#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Account
{
    float bal;
    public:
    Account():bal(35000){}
    void credit(int amount)
    {
        bal+=amount;
        cout<<"Amount added succesfully!"<<endl;
    }
    void debit(int amount)
    {
        bal-=amount;
        if(bal<0)
        bal=0;
        cout<<"Amount withdrawn succesfully!"<<endl;
    }
    float getbalance()
    {
        return bal;
    }
};
int main()
{
    Account a1;
    int amount;
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    a1.credit(amount);
    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    a1.debit(amount);
    cout<<"Final Balance: "<<a1.getbalance();
}
