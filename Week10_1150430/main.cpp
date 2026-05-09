#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- 四十六、樣板 (Templates)：讓函式支援各種型態 ---
template <typename T>
void printResult(T val) {
    cout << "計算結果為: " << val << endl;
}

// --- 四十五、遞迴 (Recursion)：計算階乘 (Factorial) ---
long long factorial(int n) {
    if (n <= 1) return 1; // 終止條件 (Base case)
    return n * factorial(n - 1); // 遞歸步驟
}

int main() {
    // --- 四十六、例外處理 (Exception Handling) ---
    try {
        int input;
        cout << "請輸入一個數字來計算階乘 (輸入負數會噴錯誤): ";
        cin >> input;

        if (input < 0) {
            throw "錯誤：不能輸入負數！"; // 拋出例外
        }
        
        printResult(factorial(input));

    } catch (const char* msg) {
        cerr << msg << endl; // 抓到錯誤
    }

    // --- 四十六、Lambda 運算式：快速定義小邏輯 ---
    vector<int> scores = {36, 70, 90, 55, 80};
    int count = 0;
    
    // 使用 Lambda 統計及格人數
    for_each(scores.begin(), scores.end(), [&](int s) {
        if (s >= 60) count++;
    });

    cout << "及格人數 (Lambda 統計): " << count << " 人" << endl;

    // --- 四十七、RAII 概念提醒 ---
    // 在現代 C++ 中，盡量使用智能指標或 STL 容器
    // 它們會自動幫你 delete 記憶體，避免 Memory Leak。

    return 0;
}