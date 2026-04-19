#include "LibraryItem.h"

LibraryItem::LibraryItem(string t, int i)
    : title(t), id(i), isAvailable(true) {}

string LibraryItem::getTitle() const { 
  return title;
 }
int LibraryItem::getId() const { 
  return id;
 }
bool LibraryItem::getAvailability() const {
   return isAvailable; 
  }
void LibraryItem::setAvailability(bool status) { 
  isAvailable = status; 
}
