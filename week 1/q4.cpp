#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float weight;
	float pounds;
	int n;
	cout<<"enter weight"<<endl;
	cin>>weight;
	pounds=weight*2.2;
	cout<<"converted rate is: "<<pounds<<endl;
	cout<<fixed<<setprecision(2)<<pounds<<endl;
	
	

	return 0;
}
