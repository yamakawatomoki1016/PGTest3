#include "player.h"
#include <Novice.h>

Player::Player() : x(640), y(650), speed(5.0f), isAlive(true){}

void Player::Update(char* keys, char* preKeys) {
    if (isAlive) {
        if (keys[DIK_A]) x -= speed;
        if (keys[DIK_D]) x += speed;
        if (keys[DIK_W]) y -= speed;
        if (keys[DIK_S]) y += speed;

        if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
            bullets.push_back(Bullet(x, y - 20));
        }

        for (auto& bullet : bullets) {
            bullet.Update();
        }

        bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
            [](Bullet& b) { return !b.IsActive(); }), bullets.end());
    }
}

void Player::Draw() {
    if (isAlive) {
        Novice::DrawBox((int)x - 20, (int)y - 20, 40, 40, 0.0f, BLUE, kFillModeSolid);
    }
    // 弾を描画
    for (auto& bullet : bullets) {
        bullet.Draw();
    }
    // 死亡中は何も描画しない、または別のインジケータを表示することも可能
}

// Playerクラスの実装に追加
bool Player::IsAlive() const {
    return isAlive;
}

std::vector<Bullet>& Player::GetBullets() { return bullets; }
float Player::GetX() const { return x; }
float Player::GetY() const { return y; }
