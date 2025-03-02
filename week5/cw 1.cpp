#include <iostream>
using namespace std;
class Engine
{
    private:
    bool isRunning;
    public:
    Engine() : isRunning(false)
    {
        
    }
    void start()
    {
        if(!isRunning)
        {
            isRunning=true;
            cout<<"Engine Started!"<<endl;  
        }
        else
        {
            cout<<"Engine already running!"<<endl;
        }
    }
    void stop()
    {
        if(isRunning)
        {
            isRunning=false;
            cout<<"Engine Stopped!"<<endl;
        }
        else
        {
            cout<<"Engine already stopped"<<endl;
        }
    }
};
class Car
{
    private:
    Engine engine;
    public:
    void startCar()
    {
        cout<<"Car Starting..."<<endl;
        engine.start();
    }
    void stopCar()
    {
        cout<<"Car Stopping..."<<endl;
        engine.stop();
    }
};
int main()
{
    Car c1;
    c1.startCar();
    c1.stopCar();
    return 0;
}
