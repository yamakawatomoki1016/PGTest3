#pragma once
#include "player.h"
#include "enemy.h"
#include <vector>

enum class Scene {
    TITLE,
    GAME
};

class Game {
private:
    Scene currentScene;
    Player player;
    std::vector<Enemy> enemies;
    bool isRunning;

public:
    Game();
    void Update(char* keys, char* preKeys);
    void Draw();
    bool IsRunning() const;
};
