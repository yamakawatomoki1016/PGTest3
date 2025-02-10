#pragma once
#include "bullet.h"
#include <vector>

// Playerクラスのヘッダーに追加
class Player {
private:
    float x, y;
    float speed;
    std::vector<Bullet> bullets;
    bool isAlive; // 自機が生きているか

public:
    Player();
    void Update(char* keys, char* preKeys);
    void Draw();
    std::vector<Bullet>& GetBullets();
    float GetX() const;
    float GetY() const;
    bool IsAlive() const; // 生死状態を返すメソッド
    void Reset();
};
