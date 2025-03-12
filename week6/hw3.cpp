#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    protected:
        string sname;
        int sid;
    public:
        Student( int sid , string sname ) : sname( sname ) , sid( sid ) { }
    
        void virtual display()
        {
            cout << "student name: " << sname << endl;
            cout << "student id: " << sid << endl;
        }
};

class Marks : public Student
{
    protected:
        double oop;
        double dld;
        double mvc;
        int subsize;
    public:
        Marks( string sname , int sid , double oop , double dld , double mvc )
            : Student( sid , sname ) , oop( oop ) , dld( dld ) , mvc( mvc ) , subsize( 3 ) { }
    
        void virtual display() override
        {
            Student::display();
            cout << "oop marks: " << oop << endl;
            cout << "dld marks: " << dld << endl;
            cout << "mvc marks: " << mvc << endl;
        } 
};

class Results : public Marks
{
    private:
        double total;
        double avg;
    public:
        Results( string sname , int sid , double oop , double dld , double mvc )
            : Marks( sname , sid , oop , dld , mvc )
        {
            total = oop + dld + mvc;
            avg = total / subsize;
        }
    
        void display() override
        {
            Marks::display();
            cout << "total marks: " << total << endl;
            cout << "average marks: " << avg << endl;
        }
};

int main()
{
    vector< Results > students;
    
    students.push_back( { "simon" , 101 , 76.5 , 85.0 , 91.0 } );
    students.push_back( { "josh" , 102 , 90.0 , 67.87 , 77.5 } );
    students.push_back( { "tyler" , 103 , 90.0 , 91.5 , 88.0 } );
    
    for ( Results student : students )
    {
        cout << "------------------" << endl;
        student.display();
    }
    
    return 0;
}
