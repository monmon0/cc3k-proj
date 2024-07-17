#include "decorator.h"

Decorator::Decorator(AsciiArt *a): next{a} {} 
Decorator::~Decorator() { delete next; }
