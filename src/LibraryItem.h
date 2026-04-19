#pragma once
#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;
    int id;
    bool isAvailable;

public:
    LibraryItem(string t, int i);
    virtual ~LibraryItem() {}

    string getTitle() const;
    int getId() const;
    bool getAvailability() const;
    void setAvailability(bool status);

    virtual void displayInfo() const = 0;
};
