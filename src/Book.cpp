#include <iostream>
#include "Book.h"
#include "Exceptions.h"
using namespace std;

Book::Book(string t, int i, string a, int p)
    : LibraryItem(t, i), author(a), pageCount(p) {}

void Book::displayInfo() const {
    cout << "Book: " << title << " | Author: " << author
         << " | Pages: " << pageCount
         << " | Available: " << isAvailable << endl;
}

void Book::borrowItem() {
    if (!isAvailable)
        throw ItemAlreadyBorrowedException();

    isAvailable = false;
}

void Book::returnItem() {
    isAvailable = true;
}
