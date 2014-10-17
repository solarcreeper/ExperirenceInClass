// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete AStack template class

// First, get the declaration for the base stack class
#include "stack.h"
#include <assert.h>

// This is the declaration for AStack.
// Array-based stack implementation
template <typename E> class AStack: public Stack<E> {
private:
  int maxSize;              // Maximum size of stack
  int top;                  // Index for top element
  E *listArray;          // Array holding stack elements

public:
  AStack(int size =defaultSize)   // Constructor
    { maxSize = size; top = 0; listArray = new E[size]; }

  ~AStack() { delete [] listArray; }  // Destructor

  void clear() { top = 0; }           // Reinitialize

  void push(const E& it) {         // Put "it" on stack
    assert(top != maxSize);
    listArray[top++] = it;
  }

  E pop() {                // Pop top element
    assert(top != 0);
    return listArray[--top];
  }

  const E& topValue() const {     // Return top element
    assert(top != 0);
    return listArray[top-1];
  }

  int length() const { return top; }  // Return length
};
