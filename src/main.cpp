#include <iostream>
#include "LibraryManager.h"
#include "Book.h"
#include "Audiobook.h"
#include "Magazine.h"
#include "Exceptions.h"

using namespace std;

int main() {
    LibraryManager myLib;

    cout << "Adding items to the library..." << endl;
    myLib.addItem(new Book("The Hobbit", 10, "J.R.R. Tolkien", 310));
    myLib.addItem(new Audiobook("Atomic Habits", 11, "James Clear", 5.5));
    myLib.addItem(new Magazine("Wired", 12, 45, "Conde Nast"));

    myLib.displayAll();

    cout << "\nTesting checkout system..." << endl;
    try {
        myLib.borrowItem(10);
        cout << "Checked out item 10 successfully." << endl;
        
        cout << "Trying to check it out again: ";
        myLib.borrowItem(10); 
    } 
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "\nTesting interface restrictions..." << endl;
    try {
        cout << "Trying to borrow a magazine: ";
        myLib.borrowItem(12);
    } 
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "\nTesting invalid ID..." << endl;
    try {
        cout << "Looking for item 500: ";
        myLib.borrowItem(500);
    } 
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "\nFinal status check:" << endl;
    myLib.displayAll();

    return 0;
}
