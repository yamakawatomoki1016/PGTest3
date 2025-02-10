#include "game.h"
#include <Novice.h>

Game::Game() : isRunning(true), currentScene(Scene::TITLE) {
    for (int i = 0; i < 5; i++) {
        enemies.push_back(Enemy(static_cast<float>(200 + i * 200), 100.0f));
    }
}

void Game::Update(char* keys, char* preKeys) {
    if (currentScene == Scene::TITLE) {
        if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
            currentScene = Scene::GAME;
        }
    }
    else if (currentScene == Scene::GAME) {
        // 自機が死んでいない場合のみ更新
        if (player.IsAlive()) {
            player.Update(keys, preKeys);
        }

        for (auto& enemy : enemies) {
            enemy.Update();
        }

        // 当たり判定
        for (auto& enemy : enemies) {
            for (auto& bullet : player.GetBullets()) {
                if (enemy.IsActive() && bullet.IsActive()) {
                    float dx = enemy.GetX() - bullet.GetX();
                    float dy = enemy.GetY() - bullet.GetY();
                    if (dx * dx + dy * dy < 20 * 20) {
                        enemy.Deactivate();
                        bullet.Deactivate();
                    }
                }
            }
        }

        // 敵と自機の衝突判定
        for (auto& enemy : enemies) {
            if (enemy.IsActive()) {
                float dx = enemy.GetX() - player.GetX();
                float dy = enemy.GetY() - player.GetY();
                if (dx * dx + dy * dy < 40 * 40) {
                    player.Reset();
                    for (int i = 0; i < 5; i++) {
                        // 敵を初期位置にリセット
                        enemies[i].Reset(static_cast<float>(200 + i * 200), 100.0f);
                    }
                    currentScene = Scene::TITLE;
                }
            }
        }

        if (keys[DIK_BACKSPACE] && preKeys[DIK_BACKSPACE] == 0) {
            player.Reset();
            for (int i = 0; i < 5; i++) {
                // 敵を初期位置にリセット
                enemies[i].Reset(static_cast<float>(200 + i * 200), 100.0f);
            }
            currentScene = Scene::TITLE;
        }
    }
}


void Game::Draw() {
    if (currentScene == Scene::TITLE) {
        Novice::ScreenPrintf(500, 300, "PRESS SPACE TO START");
    }
    else if (currentScene == Scene::GAME) {
        player.Draw();
        for (auto& enemy : enemies) {
            enemy.Draw();
        }
    }
}

bool Game::IsRunning() const { return isRunning; }