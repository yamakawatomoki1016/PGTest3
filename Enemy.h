#pragma once

class Enemy {
private:
    float x, y;
    float speed;
    bool active;

public:
    Enemy(float startX, float startY);
    void Update();
    void Draw();
    bool IsActive() const;
    void Deactivate();
    float GetX() const;
    float GetY() const;
};
