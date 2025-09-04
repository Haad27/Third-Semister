#include <iostream>
#include <string>
using namespace std;

struct datas
{
    string name;
    int age;
    int salary;
};

int main()
{
    datas d1{"ahmed", 20, 2000};  // declared inside main

    cout << d1.name << " " << d1.age << " " << d1.salary << endl;

    return 0;
}
