#include <iostream>
#include <string>
#include <vector>

using namespace std;
// create a student struct
struct student
{
    string name;
    int age;
    float marks;
};
//creating another function to display the results 
void display(struct student Student)
{
    cout << "the name is :" << Student.name << endl;
    cout << "the age is :" << Student.age << endl;
    cout << "the marks is :" << Student.marks << endl;
}

int main()
{
    student Student;
    cout << "enter the name ";
    cin >> Student.name;
    cout << "enter the age ";
    cin >> Student.age;
    cout << "enter the marks ";
    cin >> Student.marks;

    // displayong the result
    display(Student);
    cout << "\nusing ptr to change the marks\n\n";
    // using ptr to change
    student *ptr = &Student;

    ptr->marks = 90;
    display(Student);
    return 0;
}
