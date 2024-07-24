#ifndef ASCIIART_H
#define ASCIIART_H

class AsciiArt {
 public:
   virtual ~AsciiArt();
   virtual char charAt(int row, int col) = 0;
};

#endif
