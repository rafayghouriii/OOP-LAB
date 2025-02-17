#include<iostream>
#include<string>
#include<cmath>
#define PI 3.141529
using namespace std;
class Circle
{
    int rad;
    public:
    Circle(int r):rad(r)
	{
		
	}
    float getarea()
    {
        return PI*rad*rad;
    }
    float getperimeter()
    {
        return 2*PI*rad;
    }
};
int main()
{
    Circle c1(17.5);
    cout<<"Area: "<<c1.getarea()<<endl;
    cout<<"Perimeter: "<<c1.getperimeter();
}
