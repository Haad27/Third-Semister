#include <iostream>
#include <string>
#include <vector>

using namespace std;

// basic struct that will have all data
struct printer
{
    char brand[20];
    char model[20];
    int year;
    float price;
};
// display the data
void display(printer Printer)
{
    cout << "the brand is :" << Printer.brand << endl;
    cout << "the model is :" << Printer.model << endl;
    cout << "the year is :" << Printer.year << endl;
    cout << "the price is :" << Printer.price << endl;
}
// display using a pointer
void ptrdisplay(printer *Printer)
{
    cout << "the brand is :" << Printer->brand << endl;
    cout << "the model is :" << Printer->model << endl;
    cout << "the year is :" << Printer->year << endl;
    cout << "the price is :" << Printer->price << endl;
}
int main()
{

    //giving value
    printer Printer{"hp", "123-lazer", 2024, 25000};
    display(Printer);

    cout << "\ndisplay using a pointer\n";
    //decalring a pointer struct
    printer *ptr = &Printer;
    display(*ptr);
    return 0;
}
