#include<iostream>
using namespace std;
typedef struct
    {
        int empid;
        string name;
        float salary;
    } Employee;
    
typedef struct
{
    Employee emp;
    string orgnum;
    string orgname;
} Organization;

int main()
{
    Organization org;
    org.orgname="NU-Fast";
    org.orgnum="NUFAST123ABC";
    org.emp.empid=127;
    org.emp.name="Linus Sebastian";
    org.emp.salary=400000;
    cout<<"Size of structure oraganization: "<<sizeof(Organization)<<endl;
    cout<<"Organisation Name: "<<org.orgname<<endl;
    cout<<"Organisation Number: "<<org.orgnum<<endl;
    cout<<"Employee Id: "<<org.emp.empid<<endl;
    cout<<"Employee Name: "<<org.emp.name<<endl;
    cout<<"Salary: "<<org.emp.salary<<endl;
}
