#ifndef DECORATOR_H
#define DECORATOR_H

#include "asciiart.h"

class Decorator: public AsciiArt {
    protected:
    AsciiArt * next;    
    public:
    // Constructor and destructor 
    Decorator(AsciiArt *a): next{a} {} 
    ~Decorator();
}; 

#endif // DECORATOR_H
