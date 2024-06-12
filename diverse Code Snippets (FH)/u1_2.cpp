#include <iostream>

int main() {
    int zahl;
    bool ist_primzahl = true;

    std::cout << "Bitte geben Sie eine Zahl ein: ";
    std::cin >> zahl;

    // Überprüfen, ob die Zahl eine Primzahl ist
    for (int i = 2; i <= zahl / 2; ++i) {
        if (zahl % i == 0) {
            ist_primzahl = false;
            break;
        }
    }

    if (ist_primzahl) {
        std::cout << zahl << " ist eine Primzahl." << std::endl;
    } else {
        std::cout << zahl << " ist keine Primzahl." << std::endl;
        std::cout << "Teiler von " << zahl << " sind: ";
        for (int i = 1; i <= zahl; ++i) {
            if (zahl % i == 0) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

