#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed the random number generator

    std::ofstream file("data.csv");

    for (int i = 0; i < 10; ++i) {
        file << rand() % 100 << "\n"; // Generate random integers between 0 and 99
    }

    file.close();

    return 0;
}