#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
 void printBook(struct Books b)
    {
        cout << "Book title : " << b.title << endl;
        cout << "Book author : " << b.author << endl;
        cout << "Book subject : " << b.subject << endl;
        cout << "Book id : " << b.book_id << endl;
    }
int main()
{

    Books Book1 = {"C++", "A", "C++", 1};
    Books Book2 = {"C++", "B", "C++", 2};
   

    printBook(Book1);
    printBook(Book2);
    return 0;
}
