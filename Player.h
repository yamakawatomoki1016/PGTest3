#pragma once
#include "bullet.h"
#include <vector>

class Player {
private:
    float x, y;
    float speed;
    std::vector<Bullet> bullets;
    bool isAlive; 

public:
    Player();
    void Update(char* keys, char* preKeys);
    void Draw();
    std::vector<Bullet>& GetBullets();
    float GetX() const;
    float GetY() const;
    bool IsAlive() const;
    void Reset();
};
