#include <iostream>
#include "LibraryManager.h"
#include "Borrowable.h"
#include "Exceptions.h"

using namespace std;

LibraryManager::LibraryManager() {
}

void LibraryManager::addItem(LibraryItem* item) {
    items.push_back(item);
}

void LibraryManager::removeItem(int id) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->getId() == id) {
            delete items[i]; 
            items.erase(items.begin() + i);
            return;
        }
    }
    throw ItemNotFoundException();
}

LibraryItem* LibraryManager::findItem(int id) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->getId() == id) {
            return items[i];
        }
    }
    throw ItemNotFoundException();
}

void LibraryManager::displayAll() const {
    cout << "\n--- Library Catalog ---" << endl;
    for (int i = 0; i < items.size(); i++) {
        items[i]->displayInfo();
    }
    cout << "-----------------------" << endl;
}

void LibraryManager::borrowItem(int id) {
    LibraryItem* item = findItem(id); 
    
    Borrowable* bItem = dynamic_cast<Borrowable*>(item);
    
    if (bItem != nullptr) {
        bItem->borrowItem();
    } else {
        throw InvalidOperationException();
    }
}

void LibraryManager::returnItem(int id) {
    LibraryItem* item = findItem(id);
    
    Borrowable* bItem = dynamic_cast<Borrowable*>(item);
    
    if (bItem != nullptr) {
        bItem->returnItem();
    } else {
        throw InvalidOperationException();
    }
}
