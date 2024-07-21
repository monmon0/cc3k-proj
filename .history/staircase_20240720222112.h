class Enemy : public Character {
public:
    Enemy(AsciiArt *next, char race, int x, int y, int hp, int atk, int def);

    ~Enemy() = default; 

    bool fPressed = false; 
    void move();
    bool isDead() { return hp <= 0; }
    void attack(Player& pc) { pc.changeHP(-getAtk()); }
    char charAt(int row, int col, int tick) override;
};
