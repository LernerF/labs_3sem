#ifndef NPC_HPP
#define NPC_HPP

#include <string>

class NPC {
public:
    enum class Type { TRADER, SQUIRREL, KNIGHT };

    NPC(std::string name, Type type, int x, int y);
    void move(int dx, int dy, int max_x, int max_y);
    bool isAlive() const;
    void kill();
    std::string getName() const;
    Type getType() const;
    int getX() const;
    int getY() const;

private:
    std::string name;
    Type type;
    int x, y;
    bool alive;
};

#endif