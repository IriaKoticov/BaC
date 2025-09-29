#include "Game.h"

Game::Game() : gameOver(false), attempts(0) {}

bool Game::isGameOver() const {
    return gameOver;
}

int Game::getAttempts() const {
    return attempts;
}
