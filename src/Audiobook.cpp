#include <iostream>
#include "Audiobook.h"
#include "Exceptions.h"
using namespace std;

Audiobook::Audiobook(string t, int i, string n, double d)
    : LibraryItem(t, i), narrator(n), duration(d) {}

void Audiobook::displayInfo() const {
    cout << "Audiobook: " << title << " | Narrator: " << narrator
         << " | Duration: " << duration
         << " | Available: " << isAvailable << endl;
}

void Audiobook::borrowItem() {
    if (!isAvailable)
        throw ItemAlreadyBorrowedException();

    isAvailable = false;
}

void Audiobook::returnItem() {
    isAvailable = true;
}
