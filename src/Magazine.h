#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    int issueNumber;
    string publisher;

public:
    Magazine(string t, int i, int issue, string pub);

    void displayInfo() const override;
};
