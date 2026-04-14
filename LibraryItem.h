#include <iostream>
#include <vector>
#include <string>

class LibraryItem
{
  protected:
    string title;
    int id;
    bool isAvaliable;
  
  public:
    LibraryItem();
    virtual ~LibraryItem();
    
    virtual void displayinfo() const = 0;
    virtual void getTitle();
    
    string getTitle();
    int getId();
}
