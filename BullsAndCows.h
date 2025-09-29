#ifndef BULLSANDCOWS_H
#define BULLSANDCOWS_H

#include "Game.h"
#include <string>
#include <vector>

class BullsAndCows : public Game {
private:
    std::string secretNumber;
    std::vector<std::pair<std::string, std::string>> history;
    int numberLength;

    std::string generateSecretNumber();
    bool isValidGuess(const std::string& guess) const;
    std::pair<int, int> calculateBullsAndCows(const std::string& guess) const;
    std::string getHint(const std::string& guess) const;

public:
    BullsAndCows(int length = 4);
    void initialize() override;
    void play() override;
    void displayResult() override;
    void displayHistory() const;
};

#endif
