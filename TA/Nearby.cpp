#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    ifstream file("data.csv");
    int input_value;
    cin >> input_value;

    if (!file.is_open()) {
        cerr << "ファイルを開けませんでした。" << endl;
        return 1;
    }

    vector<int> data;
    int num;
    while (file >> num) {
        data.push_back(num);
    }

    int closest_value = data[0];
    int min_diff = abs(input_value - data[0]);
    for (int i = 1; i < data.size(); ++i) {
        int diff = abs(input_value - data[i]);
        if (diff < min_diff) {
            min_diff = diff;
            closest_value = data[i];
        }
    }

    cout << "入力値にもっとも近い値: " << closest_value << endl;

    file.close();

    return 0;
}
