#pragma once
#include <exception>
using namespace std;

class ItemNotFoundException : public exception {
public:
    const char* what() const noexcept override {
        return "Item not found.";
    }
};

class ItemAlreadyBorrowedException : public exception {
public:
    const char* what() const noexcept override {
        return "Item already borrowed.";
    }
};

class InvalidOperationException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid operation for this item.";
    }
};
