#include "LibraryItem.h"
#include "Borrowable.h"

class Audiobook : public LibraryItem, public Borrowable {
private:
    string narrator;
    double duration;

public:
    Audiobook(string t, int i, string n, double d);

    void displayInfo() const override;
    void borrowItem() override;
    void returnItem() override;
};
