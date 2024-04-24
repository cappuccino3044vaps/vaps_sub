#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("data.csv");
    std::vector<int> data;
    int num;

    while (file >> num) {
        data.push_back(num);
    }

    int min_diff = INT_MAX;
    int num1, num2;

    for (int i = 0; i < data.size(); ++i) {
        for (int j = i + 1; j < data.size(); ++j) {
            int diff = abs(data[i] - data[j]);
            if (diff < min_diff) {
                min_diff = diff;
                num1 = data[i];
                num2 = data[j];
            }
        }
    }

    std::cout << "最も差が小さい2つの値: " << num1 << ", " << num2 << std::endl;

    return 0;
}
