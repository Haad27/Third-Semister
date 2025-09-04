#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    int age;
    string address;
};

// Function takes an array of students and its size
void f1(Student students[], int SIZE)
{
    cout << "\nStudents with age = 14:\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (students[i].age == 14)
        {
            cout << students[i].name << "\n";
        }
    }
}

void f2(Student students[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (students[i].rollNo % 2 == 0)
        {
            cout << students[i].name << "\n";
        }
    }
}
void f3(Student students[], int SIZE)
{
    int roll;
    cout << "enter the roll no\n";
    cin >> roll;
    for (int i = 0; i < SIZE; i++)
    {
        if (students[i].rollNo == roll)
        {
            cout << students[i].name << "\n";
        }
        else
        {
            cout << "not found\n";
        }
    }
}

int main()
{
    const int SIZE = 12;
    Student students[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;

        cout << "Name: ";
        getline(cin, students[i].name);

        do
        {
            cout << "Age (11-14): ";
            cin >> students[i].age;
        } while (students[i].age < 11 || students[i].age > 14);

        cout << "Address: ";
        getline(cin, students[i].address);

        cout << endl;
    }

    f1(students, SIZE);
    f2(students, SIZE);

    return 0;
}
