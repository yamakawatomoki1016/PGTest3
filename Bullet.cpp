#include "bullet.h"
#include <Novice.h>

Bullet::Bullet(float startX, float startY) : x(startX), y(startY), speed(10.0f), active(true) {}

void Bullet::Update() {
    if (active) {
        y -= speed;
        if (y < 0) active = false;
    }
}

void Bullet::Draw() {
    if (active) {
        Novice::DrawBox((int)x - 5, (int)y - 10, 10, 10, 0.0f, WHITE, kFillModeSolid);
    }
}

bool Bullet::IsActive() const { return active; }
void Bullet::Deactivate() { active = false; }
float Bullet::GetX() const { return x; }
float Bullet::GetY() const { return y; }
