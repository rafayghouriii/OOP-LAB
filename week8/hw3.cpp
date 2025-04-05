#include <iostream>
using namespace std;
class Person
{
    private:
    int empid;
    string name;
    int monthlyincome;
    public:
    Person(int id, int minc,string n):empid(id),monthlyincome(minc),name(n){}
    void setname(string n)
    {
        name=n;
    }
    void setempid(int id)
    {
        empid=id;
    }
    void setmonthlyincome(int minc)
    {
        monthlyincome=minc;
    }
    string getname() const
    {
        return name;
    }
    int getempid() const
    {
        return empid;
    }
    int getmonthlyincome() const
    {
        return monthlyincome;
    }
};
class Admin : public Person
{
    private:
    float bonus;
    public:
    Admin(int id, int minc,string n,float b=5): Person(id,minc,n),bonus(b){}
    float calculatebonus() const
    {
        return (bonus/100)*getmonthlyincome();
    }
    void display()
    {
        cout<<"ID: "<<getempid()<<"\nName: "<<getname()<<"\nMonthly Income: "<<getmonthlyincome()<<"\nBonus: "<<calculatebonus();
    }
};
class Accounts : public Person
{
    private:
    float bonus;
    public:
    Accounts(int id, int minc,string n,float b=5): Person(id,minc,n),bonus(b){}
    float calculatebonus() const
    {
        return (bonus/100)*getmonthlyincome();
    }
    void display()
    {
        cout<<"ID: "<<getempid()<<"\nName: "<<getname()<<"\nMonthly Income: "<<getmonthlyincome()<<"\nBonus: "<<calculatebonus();
    }
};
int main()
{
    Admin ob(22,1000,"Fahaam",5);
    ob.display();
    return 0;
}
