//movie name, adult ticket price, child ticket price,number of adult tickets sold, number of child tickets sold, and percentage of the gross amount to be
//donated to the charity
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string movie;
	float adultprice,childprice,perc;
	int numadulttickets,numchildtickets;
	cout<<"enter movie name"<<endl;
	getline(cin,movie);
	cout<<"enter number of adult ticket price"<<endl;
	cin>>adultprice;
	cout<<"enter number of child ticket price"<<endl;
	cin>>childprice;	
	cout<<"enter number of adult ticket sold"<<endl;
	cin>>numadulttickets;
	cout<<"enter number of child ticket sold"<<endl;
	cin>>numchildtickets;
	cout<<"enter percentage of gross amount to be donated"<<endl;
	cin>>perc;
	cout<<"movie name: "<<movie<<endl; //cout << "Formatted to 2 decimal places: " << fixed << setprecision(2) << num << endl;
	cout<<"Number of tickets sold: "<<fixed<<setprecision(2)<<numadulttickets+numchildtickets<<endl;
	float grossamount=(adultprice*numadulttickets)+(childprice*numchildtickets);
	cout<<"Gross Amount: "<<fixed<<setprecision(2)<<grossamount<<endl;
	cout<<"Percentage of Gross Amount to be donated: "<<fixed<<setprecision(2)<<perc<<"%"<<endl;
	float donated= (perc/100)*grossamount;
	cout<<"Amount Donated: "<<fixed<<setprecision(2)<<donated<<endl;
	cout<<"Net sale: "<<fixed<<setprecision(2)<<grossamount-donated<<endl;		
	return 0;
}
