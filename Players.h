#ifndef PLAYERS_H
#define PLAYERS_H


class Player: public Decorator {
    protected:
    AsciiArt * next;    
    
    public:
    // Constructor and destructor 
    Player(AsciiArt *a): next{a} {} 
    ~Player();
}; 

#endif // DECORATOR_H
