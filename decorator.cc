#include "decorator.h"

Decorator::Decorator(AsciiArt *a): next{a} {} 
Decorator::~Decorator() { if (next != nullptr) delete next; }
