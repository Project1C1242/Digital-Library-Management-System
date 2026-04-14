#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LibraryItem
{
protected:
    string title;
    int id;
    bool isAvaliable;

public:
    LibraryItem(string title, int id);
    virtual ~LibraryItem();

    virtual void displayInfo() const = 0;

    string getTitle();
    int getId();
};
