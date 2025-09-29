#include <iostream>
#include "BullsAndCows.h"

void displayMenu() {
    std::cout << "=== БЫКИ И КОРОВЫ ===\n";
    std::cout << "1. Начать новую игру (4 цифры)\n";
    std::cout << "2. Начать сложную игру (7 цифр)\n";
    std::cout << "3. Выйти\n";
    std::cout << "Выберите опцию: ";
}

int main() {

    int choice;

    do {
        displayMenu();
        if (!(std::cin >> choice)){
            if(std::cin.eof())
                    { throw "eof"; }
            std::cin.clear();
            std::cin.get();
            choice = 0;
        }


        switch (choice) {
            case 1: {
                BullsAndCows game(4);
                game.play();
                game.displayResult();
                break;
            }
            case 2: {
                BullsAndCows game(7);
                game.play();
                game.displayResult();
                break;
            }
            case 3:
                std::cout << "До свидания!\n";
                break;
            default:
                std::cout << "Неверный выбор!\n";
        }


        if (choice != 3) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.ignore();
            std::cin.get();
        }


    } while (choice != 3);

    return 0;
}
