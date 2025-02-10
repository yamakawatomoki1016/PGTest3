#include "enemy.h"
#include <Novice.h>
#include <cstdlib> 

Enemy::Enemy(float startX, float startY) : x(startX), y(startY), speed(3.0f), active(true), respawnTimer(0) {}

void Enemy::Update() {
    if (active) {
        x += speed;
        if (x > 1280 || x < 0) {
            speed = -speed;
        }
    }
    else {
        if (respawnTimer > 0) {
            respawnTimer--;
        }
        else {
            Respawn(); 
        }
    }
}

void Enemy::Draw() {
    if (active) {
        Novice::DrawBox((int)x - 20, (int)y - 20, 40, 40, 0.0f, RED, kFillModeSolid);
    }
}

bool Enemy::IsActive() const { return active; }
void Enemy::Deactivate() {
    active = false;
    respawnTimer = 120;  
}

void Enemy::Respawn() {
    x = (float)(rand() % 1100 + 100);  // 100～1200pxの範囲でランダム
    y = 100;
    active = true;
}

float Enemy::GetX() const { return x; }
float Enemy::GetY() const { return y; }

void Enemy::Reset(float startX, float startY)
{
    x = startX;
    y = startY;
    active = true;
    respawnTimer = 0;  
}
