#include <iostream>
using namespace std;
class Task
{
    private:
    int a;
    public:
    Task(int b=0):a(b){}
    Task& operator--()
    {
        a*=4;
        return *this;
    }
    Task& operator--(int)
    {
        Task temp=*this;
        a/=4;
        return temp;
    }
    void display() const
    {
        cout<<"Value of a: "<<a<<endl;
    }
};
int main()
{
    Task obj(12);
    obj.display();
    
    obj--;
    obj.display();
    
    --obj;
    obj.display();
    
    return 0;
}
