#include <iostream>
#include <string>
using namespace std;

int main() {
    char choice;
    do {
        int score;
        cout << "請輸入成績 (0-100): ";
        cin >> score;

        if (score >= 90) {
            cout << "等級: A (大神請受我一拜)" << endl;
        } else if (score >= 60) {
            cout << "等級: B (低空飛過，真香)" << endl;
        } else {
            cout << "等級: F (準備重修，C++ 誠不我欺)" << endl;
        }

        cout << "是否繼續查詢？(y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "程式結束，感謝使用！" << endl;
    return 0;
}