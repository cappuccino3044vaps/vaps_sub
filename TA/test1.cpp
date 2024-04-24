#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream file("test1.dat");
    int num, sum = 0;
    int count = 0;
    double mean = 0, variance = 0, standard_deviation = 0;

    while (file >> num) {
        sum += num;
        count++;
    }

    if (count > 0) {
        mean = static_cast<double>(sum) / count;
        
        file.clear();
        file.seekg(0);
        
        sum = 0;
        while (file >> num) {
            sum += pow(num - mean, 2);
        }

        variance = static_cast<double>(sum) / count;
        standard_deviation = sqrt(variance);

        cout << "標準偏差: " << standard_deviation << endl;
    } else {
        cout << "No data found in the file." << endl;
    }

    file.close();
    
    return 0;
}
