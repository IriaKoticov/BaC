#include "BullsAndCows.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>

BullsAndCows::BullsAndCows(int length) : numberLength(length) {
    initialize();
}

std::string BullsAndCows::generateSecretNumber() {
    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(digits.begin(), digits.end(), g);

    std::string result;
    for (int i = 0; i < numberLength; ++i) {
        result += std::to_string(digits[i]);
    }
    return result;
}

bool BullsAndCows::isValidGuess(const std::string& guess) const {
    if (guess.length() != numberLength) return false;

    // Проверка на уникальность цифр
    for (size_t i = 0; i < guess.length(); ++i) {
        if (!isdigit(guess[i])) return false;
        for (size_t j = i + 1; j < guess.length(); ++j) {
            if (guess[i] == guess[j]) return false;
        }
    }
    return true;
}

std::pair<int, int> BullsAndCows::calculateBullsAndCows(const std::string& guess) const {
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < numberLength; ++i) {
        if (guess[i] == secretNumber[i]) {
            bulls++;
        } else if (secretNumber.find(guess[i]) != std::string::npos) {
            cows++;
        }
    }

    return {bulls, cows};
}

std::string BullsAndCows::getHint(const std::string& guess) const {
    auto [bulls, cows] = calculateBullsAndCows(guess);
    std::stringstream ss;
    ss << guess << " - " << bulls << " бык(ов), " << cows << " коров(а)";
    return ss.str();
}

void BullsAndCows::initialize() {
    secretNumber = generateSecretNumber();
    gameOver = false;
    attempts = 0;
    history.clear();
    std::cout << "Игра 'Быки и Коровы' началась!\n";
    std::cout << "Загадано " << numberLength << "-значное число с уникальными цифрами.\n";
}

void BullsAndCows::play() {
    std::string guess;

    while (!gameOver) {
        std::cout << "\nВведите вашу догадку (" << numberLength << " цифр): ";
        std::cin >> guess;

        if (!isValidGuess(guess)) {
            std::cout << "Неверный ввод! Введите " << numberLength
                      << " уникальных цифр.\n";
            continue;
        }

        attempts++;
        auto [bulls, cows] = calculateBullsAndCows(guess);
        std::string hint = getHint(guess);
        history.push_back({guess, hint});

        std::cout << hint << std::endl;

        if (bulls == numberLength) {
            gameOver = true;
            std::cout << "\nПоздравляем! Вы угадали число " << secretNumber
                      << " за " << attempts << " попыток!\n";
        }

        if (attempts % 5 == 0) {
            std::cout << "\n--- История попыток ---\n";
            displayHistory();
        }
    }
}

void BullsAndCows::displayResult() {
    std::cout << "\n=== РЕЗУЛЬТАТЫ ИГРЫ ===\n";
    std::cout << "Загаданное число: " << secretNumber << std::endl;
    std::cout << "Количество попыток: " << attempts << std::endl;
    displayHistory();
}

void BullsAndCows::displayHistory() const {
    for (const auto& entry : history) {
        std::cout << entry.second << std::endl;
    }
}
