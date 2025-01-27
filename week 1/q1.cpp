//Write a program that finds the second highest number in a float type array of 20
//elements using pointer.
#include <iostream>
using namespace std;
int main()
{
    float arr[20];
    cout << "enter 20 elements into the array: " <<endl;
    for (int i=0;i<20;i++)
	{
        cin>>arr[i];
    }
    cout << "array elements are:"<<endl;
    for (int i=0;i<20;i++)
	{
        cout << *(arr+i)<<endl;
    }
    float max=arr[0];
    float secmax=arr[0];
    for (int i=1;i<20;i++)
	{
        if (*(arr+i) > max)
		{
            secmax = max;
            max = *(arr+i);
        } else if (*(arr+i) > secmax && *(arr+i) != max)
		{
            secmax = *(arr + i);
        }
    }
    if (secmax == max) {
        cout << "no second highest value" << endl;
    } else {
        cout << "second highest value is: "<<secmax<<endl;
    }
    return 0;
}

