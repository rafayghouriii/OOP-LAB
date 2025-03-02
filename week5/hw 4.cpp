#include <iostream>
#include <windows.h>
using namespace std;
class Blend
{
    public:
    void blendjuice()
    {
        for(int i=1;i<=5;i++)
        {
            cout<<"blending... ("<<i<<" seconds)"<<endl;
            Sleep(1000);
            system("cls");
        }
        cout<<endl;
    }
};
class Grind
{
    public:
    void grindjuice()
    {
        for(int i=1;i<=5;i++)
        {
            cout<<"grinding... ("<<i<<" seconds)"<<endl;
            Sleep(1000);
            system("cls");
        }
    }
};
class JuiceMaker
{
    Blend b;
    Grind g;
    public:
    void makejuice()
    {
        b.blendjuice();
        g.grindjuice();
        cout<<"juice is ready!"<<endl;
    }
};
int main()
{
    JuiceMaker j1;
    j1.makejuice();
}
