#pragma once

class Bullet {
private:
    float x, y;
    float speed;
    bool active;

public:
    Bullet(float startX, float startY);
    void Update();
    void Draw();
    bool IsActive() const;
    void Deactivate();
    float GetX() const;
    float GetY() const;
};
