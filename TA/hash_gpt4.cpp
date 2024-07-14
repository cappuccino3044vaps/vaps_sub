
#include <iostream>
#include <cstdlib>
#include <ctime>

// ハッシュ関数 h(x) = x % m を計算する関数
int hashFunction(int x, int m) {
    return x % m; // x を m で割った余りを返す
}

int main() {
    srand(time(nullptr)); // 乱数生成器の初期化
    int m = 20; // ハッシュテーブルのサイズ
    int x = rand() % 900 + 100; // 100から999までのランダムな数値を生成

    // ハッシュ関数を用いてハッシュ値を計算
    int hashValue = hashFunction(x, m);

    // 結果の出力
    std::cout << "生成された数値: " << x << std::endl;
    std::cout << "ハッシュ値: " << hashValue << std::endl;

    return 0;
}
