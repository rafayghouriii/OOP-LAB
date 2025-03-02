#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Car
{
    string name;
    int id;
    public:
    Car():name("Corolla"),id(0)
	{
		
	}
    Car(string n,int i):name(n),id(i)
	{
		
	}
    string getname()
	{
		return name;
	}
    int getid()
	{
		return id;
	}
};
class Garage
{
    vector<Car*> cars;
    public:
    void parkCar(Car* car)
    {
        cars.push_back(car);
        cout<<"Car parked!"<<endl<<endl;
    }
    void listCar()
    {
        for(int i=0;i<cars.size();i++)
        {
            cout<<"car "<<i+1<<": "<<endl;
            cout<<"id: "<<cars[i]->getid()<<endl;
            cout<<"name: "<<cars[i]->getname()<<endl;
            cout<<endl;
        }
    }
};
int main()
{
    Car car1("Toyota",1012);
    Garage garage;
    garage.parkCar(&car1);
    garage.listCar();
}
