#pragma once

class Borrowable {
public:
    virtual void borrowItem() = 0;
    virtual void returnItem() = 0;
    virtual ~Borrowable() {}
};