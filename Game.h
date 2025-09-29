#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
protected:
    bool gameOver;
    int attempts;

public:
    Game();
    virtual ~Game() = default;

    virtual void initialize() = 0;
    virtual void play() = 0;
    virtual void displayResult() = 0;
    virtual bool isGameOver() const;

    int getAttempts() const;
};

#endif
