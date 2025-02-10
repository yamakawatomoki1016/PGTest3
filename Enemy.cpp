#include "enemy.h"
#include <Novice.h>

Enemy::Enemy(float startX, float startY) : x(startX), y(startY), speed(3.0f), active(true) {}

void Enemy::Update() {
    if (active) {
        x += speed;
        if (x > 1280 || x < 0) {
            speed = -speed;
        }
    }
}

void Enemy::Draw() {
    if (active) {
        Novice::DrawBox((int)x - 20, (int)y - 20, 40, 40, 0.0f, RED, kFillModeSolid);
    }
}

bool Enemy::IsActive() const { return active; }
void Enemy::Deactivate() { active = false; }
float Enemy::GetX() const { return x; }
float Enemy::GetY() const { return y; }
