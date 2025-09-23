#include <iostream>
#include <string>
#include <vector>

using namespace std;
// making a struct car to have main data
struct car
{
    string brand;
    string model;
    int year;
    float price;
};
// to display car
void display(car Car[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\n brand of car " << i + 1 << " : ";
        cout << Car[i].brand << endl;
        cout << "model of car " << i + 1 << " : ";
        cout << Car[i].model << endl;
        cout << "year of car " << i + 1 << " : ";
        cout << Car[i].year << endl;
        cout << "price of car " << i + 1 << " : ";
        cout << Car[i].price << endl;
    }
}
// to find the highest price
void highest(car Car[], int size)
{
    int highest = 0;
    for (int i = 0; i < size; i++)
    {
        if (Car[i].price > highest)
        {
            highest = Car[i].price;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (Car[i].price == highest)
        {
            cout << "the car with highest price " << Car[i].brand;
        }
    }
}
int main()
{
    int num;
    cout << "how many cars do you want to have\n";
    cin >> num;
    if (num <= 1)
    {
        cout << "cant have less than or equal to one must be more than 1 more\n";
    }
    else
    {

        car cars[num];

        for (int i = 0; i < num; i++)
        {
            cout << "enter the brand of car " << i + 1 << "\n";
            cin >> cars[i].brand;
            cout << "enter the model of car " << i + 1 << "\n";
            cin >> cars[i].model;
            cout << "enter the year of car " << i + 1 << "\n";
            cin >> cars[i].year;
            cout << "enter the price of car " << i + 1 << "\n";
            cin >> cars[i].price;
        }

        car *ptr = &cars[0];
        cout << "now we are changnig the brand \n";
        ptr->brand = "BMW\n";
        display(cars, num);
        highest(cars, num);
    }
    return 0;
}
