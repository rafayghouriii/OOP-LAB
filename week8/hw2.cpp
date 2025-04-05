#include <iostream>
using namespace std;
class Shape
{
    private:
    int length;
    int width;
    public:
    Shape(int l=0 ,int w=0):length(l),width(w){}
    
    friend Shape operator+(Shape& Shape1,Shape& Shape2);
    
    void display() const
    {
        cout<<"Area: "<<Area()<<endl;
    }
    
    int Area() const
    {
        return length*width;
    }
};
Shape operator+(Shape& Shape1,Shape& Shape2)
{
    return Shape(1,(Shape1.Area())+(Shape2.Area()));
}
int main()
{
    Shape Shape1(10,10);
    Shape Shape2(20,20);
    cout<<"The Total Area of Shape 1 and 2 is: "<<endl;
    Shape Shape3=Shape1+Shape2;
    Shape3.display();
    return 0;
}
