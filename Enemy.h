#pragma once

class Enemy {
private:
    float x, y;
    float speed;
    bool active;
    int respawnTimer;

public:
    Enemy(float startX, float startY);
    void Update();
    void Draw();
    bool IsActive() const;
    void Deactivate();
    void Respawn();
    float GetX() const;
    float GetY() const;
};
