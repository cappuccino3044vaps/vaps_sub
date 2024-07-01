#include <iostream>
#include <ctime>
#include <cstdlib>

struct Node{
    int value; // ノードが保持する値
    Node* next; // 次のノードへのポインタ
};

// 新しいノードを作成し、そのポインタを返す関数
Node* createNode(int value) {
    Node* newNode = new Node; // 新しいノードを動的に確保
    newNode->value = value; // ノードの値を設定
    newNode->next = nullptr; // 次のノードへのポインタをnullに設定
    return newNode; // 新しいノードのポインタを返す
}

// リストの末尾に新しいノードを追加する関数
void appendNode(Node*& head, int value) {
    Node* newNode = createNode(value); // 新しいノードを作成
    if (head == nullptr) {
        head = newNode; // リストが空の場合、新しいノードが先頭になる
    } else {
        Node* temp = head; // 末尾のノードを見つけるために先頭から走査
        while (temp->next != nullptr) {
            temp = temp->next; // 次のノードへ移動
        }
        temp->next = newNode; // 末尾ノードの次に新しいノードを接続
    }
}

// リストの内容を標準出力に表示する関数
void printList(Node* head) {
    Node* temp = head; // 先頭からリストを走査
    while (temp != nullptr) {
        std::cout << temp->value << " -> "; // ノードの値を出力
        temp = temp->next; // 次のノードへ移動
    }
    std::cout << "nullptr" << std::endl; // リストの末尾を示す
}

int main() {
    srand(time(nullptr)); // 乱数生成器の初期化
    Node* head = nullptr; // リストの先頭を指すポインタ

    for (int i = 0; i < 10; i++) {
        int randomValue = rand() % 900 + 100; // 100から999までのランダムな数値を生成
        appendNode(head, randomValue); // リストに新しいノードを追加
    }

    printList(head); // リストの内容を表示

    // メモリの解放
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next; // 次のノードを一時的に保存
        delete current; // 現在のノードを削除
        current = next; // 次のノードへ移動
    }

    return 0;
}
