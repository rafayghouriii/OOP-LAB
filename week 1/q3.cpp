
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int id;
	float amount,surchargeamount;
	string name;
	float unitsconsumed;
	cout<<"enter id of customer"<<endl;
	cin>>id;
	cout<<"enter name of customer"<<endl;
	cin>>name;
	cout<<"enter units consumed by customer"<<endl;
	cin>>unitsconsumed;
	cout<<"Customer ID: "<<id<<endl;
	cout<<"Customer Name: "<<name<<endl;
	cout<<"Units Consumed: "<<unitsconsumed<<endl;
	if(unitsconsumed<=199)
	{
		amount=unitsconsumed*16.20;
		cout<<"Amount charges: "<<amount<<endl;
		if(amount>18000)
		{
			surchargeamount=amount*0.15;
			cout<<"Surcharge Amount: "<<surchargeamount<<endl;
			amount=amount+surchargeamount;
		}
	}
	if(unitsconsumed>=200 && unitsconsumed<300)
	{
		amount=unitsconsumed*20.10;
		cout<<"Amount charges: "<<amount<<endl;
		if(amount>18000)
		{
			surchargeamount=amount*0.15;
			cout<<"Surcharge Amount: "<<surchargeamount<<endl;
			amount=amount+surchargeamount;
		}
	}
	if(unitsconsumed>=300 && unitsconsumed<500)
	{
		amount=unitsconsumed*27.10;
		cout<<"Amount charges: "<<amount<<endl;
		if(amount>18000)
		{
			surchargeamount=amount*0.15;
			cout<<"Surcharge Amount: "<<surchargeamount<<endl;
			amount=amount+surchargeamount;
		}
	}
	if(unitsconsumed>=500)
	{
		amount=unitsconsumed*35.90;
		cout<<"Amount charges: "<<amount<<endl;
		if(amount>18000)
		{
			surchargeamount=amount*0.15;
			cout<<"Surcharge Amount: "<<surchargeamount<<endl;
			amount=amount+surchargeamount;
		}
	}
	cout<<"Net amount paid by customer: "<<amount<<endl;
	
	
	return 0;
}
