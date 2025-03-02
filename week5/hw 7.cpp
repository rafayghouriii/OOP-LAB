#include <iostream>
using namespace std;
class Student
{
private:
    const int rollno;
public:
    Student(int r) : rollno(r)
	{
		
	}
    void display() const
	{
        cout << "Student roll no#: " <<rollno<<endl;
    }
};
int main()
{
    int roll;
    cout << "Student Roll Number: ";
    cin >> roll;
    Student s(roll);
    s.display();
    return 0;
}
