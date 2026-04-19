// Week6_Memory_Management.cpp
#include <iostream>

using namespace std;

/**
 * 傳址呼叫 (Call by Address) 示範
 * 透過指標直接操作外部變數的記憶體空間
 */
void applyBonus(int* scorePtr) {
    if (scorePtr != nullptr) { // 安全性檢查：確保不是空指標
        *scorePtr += 10;       // 間接參照並修改數值
    }
}

int main() {
    // 1. 靜態變數與指標基本操作
    int rawScore = 80;
    int* p = &rawScore;

    cout << "--- 基礎指標資訊 ---" << endl;
    cout << "變數數值: " << rawScore << " | 位址: " << p << endl;

    applyBonus(p); // 傳遞位址
    cout << "更新後數值: " << rawScore << endl << endl;

    // 2. 動態記憶體分配 (Heap Allocation)
    int* dynamicData = new int(100);

    cout << "--- 動態記憶體管理 ---" << endl;
    cout << "Heap 配置數值: " << *dynamicData << endl;

    // 3. 資源釋放與安全歸零
    delete dynamicData;    // 釋放記憶體，預防 Memory Leak
    dynamicData = nullptr; // 避免變成懸空指標 (Dangling Pointer)

    // 4. const 指標限定詞示範
    int x = 10, y = 20;
    const int* ptrToConst = &x; // 不能透過 ptrToConst 改 x 的值
    int* const constPtr = &x;   // constPtr 不能改指 y 的位址

    cout << "指標操作安全確認完畢。" << endl;

    return 0;
}