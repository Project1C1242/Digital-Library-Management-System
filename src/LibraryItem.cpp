#include "LibraryItem.h"

LibraryItem::LibraryItem(string title, int id) : title(title), id(id) {}
    
string LibraryItem::getTitle()
{
  return title;
}

int LibraryItem::getId()
{
  return id;
}
