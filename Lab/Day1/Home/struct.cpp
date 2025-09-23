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
void printBook(struct Books book)
{
    cout << "Book title : " << book.title << endl;
    cout << "Book author : " << book.author << endl;
    cout << "Book subject : " << book.subject << endl;
    cout << "Book id : " << book.book_id << endl;
}
int main()
{

    Books Book1({"C++", "A", "C++", 1});
    Books Book2({"C++", "B", "C++", 2});

    printBook(Book1);
    printBook(Book2);
    return 0;
}
