
#include <iostream>
#include "LibraryManager.h"
#include "Book.h"
#include "Audiobook.h"
#include "Magazine.h"
#include "Exceptions.h"
using namespace std;

int main() {
    LibraryManager manager;

    manager.addItem(new Book("1984", 1, "Orwell", 328));
    manager.addItem(new Audiobook("Dune", 2, "Simon Vance", 21.5));
    manager.addItem(new Magazine("Time", 3, 101, "Time Inc."));

    manager.displayAll();

    try {
        manager.borrowItem(1);

        manager.borrowItem(1);
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        manager.borrowItem(3);
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}