/*Here we used a book class in a library class to get all the details of the book in a library full of books*/

#include <iostream>
#include <string>
using namespace std;

#define MAX_BOOKS 100

class Book {
private:
    string title;
    string author;
    string isbn;

public:
   Book() {} 
    Book(string tit, string aut, string ib) : title(tit), author(aut), isbn(ib) {}

    string getISBN() const {
        return isbn;
    }

    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    int numBooks;

public:
    Library() : numBooks(0) {}

    void addBook(Book book) {
        if (numBooks < MAX_BOOKS) {
            books[numBooks++] = book;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void searchBookByISBN(string isbn) {
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].getISBN() == isbn) {
                books[i].displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with ISBN " << isbn << " not found in the library." << endl;
        }
    }
};

int main() {
    Library library;

    library.addBook(Book("Trader view", "J.D. Salinger", "9780316769488"));
    library.addBook(Book("Alice in wonderland", "Harper Lee", "9780061120084"));
    library.addBook(Book("1984", "George Orwell", "9780451524935"));
    library.addBook(Book("Rich vs Poor", "Jane Austen", "9780141439518"));

    string isbn;
    cout << "Enter ISBN to search for a book: ";
    cin >> isbn;

    library.searchBookByISBN(isbn);

    return 0;
}