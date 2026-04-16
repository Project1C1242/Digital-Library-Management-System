#include <iostream>

#include "Audiobook"
#include "Book"

using namespace std;

class Borrowable
{
	public:
		virtual ~Borrowable() {};

		virtual void borrowItem() const = 0;
		virtual void returnItem() const = 0;
};
