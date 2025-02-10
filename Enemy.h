#pragma once

class Enemy {
private:
    float x, y;
    float speed;
    bool active;
    int respawnTimer; // リスポーン用タイマー

public:
    Enemy(float startX, float startY);
    void Update();
    void Draw();
    bool IsActive() const;
    void Deactivate();
    void Respawn(); // リスポーン処理
    float GetX() const;
    float GetY() const;
};
