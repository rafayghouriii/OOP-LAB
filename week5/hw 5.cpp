#include<iostream>
#include<string>
using namespace std;
class Car
{
    private:
    mutable float engineHP;
    mutable int seatingcap;
    mutable int noofspeakers;
    public:
    Car():engineHP(0),seatingcap(0),noofspeakers(0)
	{
		
	}
    void setengineHP(float hp) const
	{
        engineHP=hp;
    }
    void setseatingcap(int sc) const
	{
        seatingcap=sc;
    }
    void setnoofspeakers(int ns) const
	{
        noofspeakers=ns;
    }
    float getengineHP()
	{
		return engineHP;
	}
    int getseatingcap()
	{
		return seatingcap;
	}
    int getnoofspeakers()
	{
		return noofspeakers;
	}
    void display()
    { 
        cout<<"Engine HP: "<<getengineHP()<<endl;
        cout<<"Seating capacity: "<<getseatingcap()<<endl;
        cout<<"Number Of speakers: "<<getnoofspeakers()<<endl;
    }
};
int main()
{
    Car c1;
    c1.display();
    c1.setengineHP(800);
    c1.setnoofspeakers(3);
    c1.setseatingcap(11);
    cout<<"New Values: "<<endl;
    c1.display();
}
