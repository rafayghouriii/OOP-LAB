//Write a program that calculates the sum of all the elements in array using pointers
#include <iostream>
using namespace std;
int main()
{
	int n,sum=0;
	cout<<"enter number of elements in the array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter elements in the array"<<endl;	
	for(int i=0;i<n;i++)
	{
		cin>>*(arr+i);
	}
	for(int i=0;i<n;i++)
	{
		sum=sum+*(arr+i);
	}	
	cout<<"sum: "<<sum<<endl;
	return 0;

}
