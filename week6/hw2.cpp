#include <iostream>
#include <string>
using namespace std;
class Vehicles
{
    protected:
        double cost;
    
    public:
        Vehicles(double p) : cost(p) {}
        
        void virtual display()
        {
            cout << "cost: " << cost << endl;
        }
};

class Car : public Vehicles
{
    protected:
        int capacity;
        int doors;
        string fueltype;
    
    public:
        Car(int c, int d, string ft, double p) : capacity(c), doors(d), fueltype(ft), Vehicles(p) {}
        
        void virtual display() override
        {
            cout << "seating capacity: " << capacity << endl;
            cout << "number of doors: " << doors << endl;
            cout << "fuel type: " << fueltype << endl;
            Vehicles::display();
        }
};

class Audi : public Car
{
    string model;
    string type;
    
    public:
        Audi(int capacity, int doors, string fueltype, double cost, string mod, string t) 
            : Car(capacity, doors, fueltype, cost), model(mod), type(t) {}
        
        void display() override
        {
            cout << "model: " << model << endl;
            cout << "type: " << type << endl;
            Car::display();
        }
};

class Motorcycle : public Vehicles
{
    protected:
        int cylinders;
        int gears;
        int wheels;
    
    public:
        Motorcycle(int c, int g, int w, double p) : cylinders(c), gears(g), wheels(w), Vehicles(p) {}
        
        void virtual display() override
        {
            cout << "number of wheels: " << wheels << endl;
            
            cout << "number of cylinders: " << cylinders << endl;
            cout << "number of gears: " << gears << endl;
            Vehicles::display();
        }
};

class Yamaha : public Motorcycle
{
    string make;
    string type;
    
    public:
        Yamaha(int cylinders, int gears, int wheels, double cost, string mak, string t) 
            : Motorcycle(cylinders, gears, wheels, cost), make(mak), type(t) {}
        
        void display() override
        {
            cout << "make: " << make << endl;
            cout << "type: " << type << endl;
            Motorcycle::display();
        }
};

int main()
{
    Audi a(5, 4, "petrol", 60000, "A6", "sedan");
    Yamaha y(2, 6, 2, 15000, "YZF-R1", "sportbike");
    cout << "audi details:\n";
    a.display();
    cout << endl;
    
    cout << "yamaha details:\n";
    y.display();
    
    return 0;
}

