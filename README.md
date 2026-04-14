Digital Library Management System
Overview:
This program emulates a digital library system using object-oriented programming in C++. Different media types are created and managed through a central library manager.

Design Architecture: Digital Library Simulation
LibraryItem (Abstract Base Class)

This class serves as the foundational blueprint for the entire library ecosystem. By defining a common ancestor, the system ensures that every piece of media adheres to a universal standard.
    - Encapsulated State: It centralizes shared attributes, specifically the item's title (string), id (integer), and availability status (boolean). By storing these as protected or private members, it prevents external modification while allowing derived classes to inherit this core identity.
    
    - Enforced Abstraction: It utilizes pure virtual functions (e.g., virtual void displayInfo() const = 0;). This makes LibraryItem an abstract class, meaning it cannot be instantiated directly. Instead, it forces a contract: any specific media type created from this blueprint must provide its own unique logic for displaying its information

    - Memory Safety: It includes a virtual destructor to ensure that when a derived object is deleted via a base class pointer, the derived class's destructor is called first, preventing resource leaks.

  Borrowable (Interface):
  This class acts as an interface, adhering to the Interface Segregation Principle. Not all library items can be checked out (e.g., a reference magazine), so this behavior is kept separate from the base LibraryItem class.
      - Behavioral Contract: It contains only pure virtual functions, specifically borrowItem() and returnItem().
      - Selective Implementation: Media that can be physically or digitally checked out inherit from both LibraryItem (for core identity) and Borrowable (for checkout functionality), keeping the class hierarchy modular.

  Concrete Media (Derived Classes):
      Book:
        - Inheritance: Uses multiple inheritance, extending both LibraryItem and Borrowable.
        - State Management: Tracks unique internal attributes: an author (string) and page count (integer).
        - Behavior: Implements the required borrowItem() and returnItem() methods, and overrides displayInfo() to output its specific book details.

     Audiobook: 
       - Inheritance: Uses multiple inheritance, extending both LibraryItem and Borrowable.
       - State Management: Tracks its unique attributes: a narrator (string) and duration (double).
       - Behavior: Implements borrowItem() and returnItem(), and overrides displayInfo() to output its audio-specific details.

     Magazine:
       - Inheritance: Inherits solely from LibraryItem.
       - State Management: Tracks its issue number (integer) and publication month (string).
       - Behavior: Does not implement the Borrowable interface, making it a "reference-only" item. It overrides displayInfo() to output its publication details.

LibraryManager (The Central Hub):
  This class acts as the orchestrator for the entire system, demonstrating the power of OOP relationships and dynamic memory.

      - Polymorphic Storage: Instead of maintaining separate lists for books, audiobooks, and magazines, it stores all items in generic containers (like std::vector) using base class pointers (LibraryItem*).
      
      - Runtime Polymorphism (Dynamic Binding): When iterating through the system to display the catalog, the manager simply calls item->displayInfo() on every pointer. Because displayInfo() is virtual, the program uses the vtable to dynamically look up and execute the correct, specific method for that object at runtime without the Manager needing to know the item's concrete type.
      
      - Resource Acquisition Is Initialization (RAII): Since media objects are dynamically allocated on the heap (using the new keyword), the Manager takes ownership of their lifecycles. Its destructor loops through the storage vector and explicitly calls delete on every pointer, ensuring safe memory management and zero memory leaks upon shutdown.

  Error Handling Architecture:
 The system abandons traditional error codes in favor of a robust, modern C++ exception-handling design. By creating custom exception classes, the program can throw and catch highly specific, descriptive errors.
      - ItemNotFoundException: Triggered by the LibraryManager if a user or system process attempts to query, update, or borrow an item using an ID that does not exist in the active registry.

      - ItemAlreadyBorrowedException: Triggered when a method call contradicts the current physical reality of the item (e.g., calling borrowItem() on a Book or Audiobook that is already checked out by another user).

      - InvalidOperationException: Triggered when a user attempts an unsupported action on a specific media type (e.g., attempting to borrow a Magazine, which is strictly for in-library reference).
