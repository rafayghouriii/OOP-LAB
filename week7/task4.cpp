#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course;

class Person {
protected:
    string name;
    int id;
    string address;
    string phone;
    string mail;

public:
    Person(string n, int i, string a, string p, string m)
        : name(n), id(i), address(a), phone(p), mail(m) {}

    virtual void display()
    {
        cout << "Name: " << name << "\nID: " << id
             << "\nAddress: " << address << "\nPhone: " << phone
             << "\nEmail: " << mail << "\n";
    }

    string getName()
    {
        return name;
    }
    
    int getId()
    {
        return id;
    }
};

class Course {
    int courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(int id, string name, int cr, string ins, string sch)
        : courseId(id), courseName(name), credits(cr), instructor(ins), schedule(sch) {}

    void display()
    {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << "\n";
    }

    string getCourseName()
    {
        return courseName;
    }
};

class Student : public Person {
    vector<Course> coursesEnrolled;
    double gpa;
    int enrollmentYear;

public:
    Student(string n, int i, string a, string p, string m, vector<Course> c, double g, int y)
        : Person(n, i, a, p, m), coursesEnrolled(c), gpa(g), enrollmentYear(y) {}

    void enrollCourse(Course c)
    {
        coursesEnrolled.push_back(c);
        cout << name << " enrolled in " << c.getCourseName() << "\n";
    }

    void display() override
    {
        Person::display();
        cout << "GPA: " << gpa << "\nEnrollment Year: " << enrollmentYear << "\nCourses: ";
        for (auto &c : coursesEnrolled) cout << c.getCourseName() << " ";
        cout << "\n";
    }
};

class Professor : public Person {
    string department;
    vector<Course> coursesTaught;
    double salary;

public:
    Professor(string n, int i, string a, string p, string m, string d, vector<Course> c, double s)
        : Person(n, i, a, p, m), department(d), coursesTaught(c), salary(s) {}

    void display() override
    {
        Person::display();
        cout << "Department: " << department << "\nSalary: " << salary << "\nCourses: ";
        for (auto &c : coursesTaught) cout << c.getCourseName() << " ";
        cout << "\n";
    }
};

int main()
{
    Course math(201, "Calculus", 4, "Dr. Khan", "Mon Wed 9AM");
    Course physics(202, "Mechanics", 3, "Dr. Patel", "Tue Thu 11AM");
    vector<Course> studentCourses = {math, physics};
    Student studentOne("Sara Ahmed", 3001, "Lahore", "03451234567", "sara@mail.com", studentCourses, 3.9, 2022);

    vector<Course> profCourses = {math};
    Professor professorOne("Dr. Rehman", 4001, "Islamabad", "03001234567", "rehman@mail.com", "Mathematics", profCourses, 75000);

    studentOne.display();
    cout << "\n";
    professorOne.display();

    return 0;
}
