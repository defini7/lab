#include <iostream>

int main() {
    srand(time(NULL));

    int n = -1;
    int answer = rand() % 10;

    while (answer != n) {
        std::cout << "Write a number (0-10): ";
        std::cin >> n;
    }

    std::cout << "Right!\n";

    return 0;
}
