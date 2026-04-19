#pragma once
#include "LibraryItem.h"
#include "Borrowable.h"

class Book : public LibraryItem, public Borrowable {
private:
    string author;
    int pageCount;

public:
    Book(string t, int i, string a, int p);

    void displayInfo() const override;
    void borrowItem() override;
    void returnItem() override;
};
