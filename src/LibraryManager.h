#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H
#include <vector>
#include "LibraryItem.h"

using namespace std; 

class LibraryManager{
private: 
    vector<LibraryItem*> items;
public: 
    LibraryManager()
    void addItem(LibraryItem* item);
    void removeItem(int id);
    LibraryItem* findItem(int id);
    void displayAll() const;
    
    void borrowItem(int id);
    void returnItem(int id);
};

#endif
