#include <iostream>
#include "Magazine.h"
using namespace std;

Magazine::Magazine(string t, int i, int issue, string pub)
    : LibraryItem(t, i), issueNumber(issue), publisher(pub) {}

void Magazine::displayInfo() const {
    cout << "Magazine: " << title
         << " | Issue: " << issueNumber
         << " | Publisher: " << publisher << endl;
}
