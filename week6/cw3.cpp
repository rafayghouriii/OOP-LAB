#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee 
{
       protected:
       int id;
       string name;

       public:
       Employee(int empid, const string& empname)
       {
              id=empid;
              name=empname;
       }

       virtual ~Employee()=default;

       virtual void display() const 
       {
              cout << "id: " << id << ", name: " << name << endl;
       }
};

class IOrderTaker 
{
       public:
       virtual ~IOrderTaker()=default;
       virtual void takeorder(const string& order)=0;
};

class IOrderPreparer 
{
       public:
       virtual ~IOrderPreparer()=default;
       virtual void prepareorder(const string& order)=0;
};

class IBiller 
{
       public:
       virtual ~IBiller()=default;
       virtual void generatebill(double amount)=0;
};

class Waiter : public Employee, public IOrderTaker 
{
       public:
       Waiter(int empid, const string& empname) : Employee(empid, empname) {}

       void takeorder(const string& order) override 
       {
              cout << "waiter " << name << " is taking order: " << order << endl;
       }
};

class Chef : public Employee, public IOrderPreparer 
{
       public:
       Chef(int empid, const string& empname) : Employee(empid, empname) {}

       void prepareorder(const string& order) override 
       {
              cout << "chef " << name << " is preparing order: " << order << endl;
       }
};

class Cashier : public Employee, public IBiller 
{
       public:
       Cashier(int empid, const string& empname) : Employee(empid, empname) {}

       void generatebill(double amount) override 
       {
              cout << "cashier " << name << " is generating a bill for $" << amount << endl;
       }
};

class Manager : public Employee, public IOrderTaker, public IBiller 
{
       public:
       Manager(int empid, const string& empname) : Employee(empid, empname) {}

       void takeorder(const string& order) override 
       {
              cout << "manager " << name << " is taking order: " << order << endl;
       }

       void generatebill(double amount) override 
       {
              cout << "manager " << name << " is generating a bill for $" << amount << endl;
       }
};

class Menu 
{
       protected:
       string name;
       double basecost;

       public:
       Menu(const string& menuname, double cost) 
       {
              name=menuname;
              basecost=cost;
       }

       virtual ~Menu()=default;

       virtual double calculatetotalcost() const 
       {
              return basecost;
       }

       virtual void display() const 
       {
              cout << "menu: " << name << ", base cost: $" << basecost << endl;
       }
};

class FoodMenu : public Menu 
{
       public:
       FoodMenu(const string& menuname, double cost) : Menu(menuname, cost) {}

       double calculatetotalcost() const override 
       {
              return basecost * 0.9;
       }

       void display() const override 
       {
              cout << "food menu - ";
              Menu::display();
              cout << "total cost (after combo discount): $" << calculatetotalcost() << endl;
       }
};

class BeverageMenu : public Menu 
{
       private:
       double taxrate;

       public:
       BeverageMenu(const string& menuname, double cost, double tax) : Menu(menuname, cost) 
       {
              taxrate=tax;
       }

       double calculatetotalcost() const override 
       {
              return basecost * (1 + taxrate);
       }

       void display() const override 
       {
              cout << "beverage menu - ";
              Menu::display();
              cout << "total cost (after tax): $" << calculatetotalcost() << endl;
       }
};

int main() 
{
       Waiter waiter(1,"Alan");
       Chef chef(2,"Mike");
       Cashier cashier(3,"Ramson");
       Manager manager(4,"Hailey");

       FoodMenu foodmenu("pizza combo", 20.0);
       BeverageMenu beveragemenu("soft drinks", 4.0, 0.2);

       vector<IOrderTaker*> ordertakers={&waiter, &manager};
       for(auto* ordertaker : ordertakers) 
       {
              ordertaker->takeorder("Large pizza");
       }

       chef.prepareorder("Large pizza");
							
       vector<IBiller*> billers={&cashier, &manager};
       for(auto* biller : billers) 
       {
              biller->generatebill(25.0);
       }

       vector<Menu*> menus={&foodmenu, &beveragemenu};
       for(auto* menu : menus) 
       {
              menu->display();
       }

       return 0;
}

