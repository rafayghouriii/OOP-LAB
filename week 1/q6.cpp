#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string name;
	float avg,sum=0;
	float arr[5];
	cout<<"enter student name"<<endl;
	getline(cin,name);
	cout<<"enter test scores"<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];		
	}
	cout<<"Student name: "<<name<<endl;
	cout<<"Test scores: ";
	for(int i=0;i<5;i++)
	{
		sum=sum+arr[i];
		cout<<arr[i];
		cout<<" ";
	} 
	cout<<" "<<endl;;
	avg=sum/5;
	cout<<"average test score: "<<avg<<endl;
    
    return 0;
}
